#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import random
import time
import sys

try:
    import msvcrt
    WINDOWS = True
except ImportError:
    import tty
    import termios
    WINDOWS = False

# 定义颜色和格式化常量
class Color:
    RESET = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    RED = '\033[31m'
    GREEN = '\033[32m'
    YELLOW = '\033[33m'
    BLUE = '\033[34m'
    MAGENTA = '\033[35m'
    CYAN = '\033[36m'
    WHITE = '\033[37m'
    BG_BLUE = '\033[44m'
    BG_GREEN = '\033[42m'
    BG_YELLOW = '\033[43m'
    HIDE_CURSOR = '\033[?25l'  # 隐藏光标
    SHOW_CURSOR = '\033[?25h'  # 显示光标

# 菜单项目类
class MenuItem:
    def __init__(self, text, action=None, submenu=None):
        self.text = text
        self.action = action  # 函数或回调
        self.submenu = submenu  # 子菜单列表

# 获取终端宽度
def get_terminal_width():
    try:
        terminal_width = os.get_terminal_size().columns
    except OSError:
        terminal_width = 80
    return terminal_width

# 清屏函数
def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

# 打印分隔线
def print_separator(char='-', color=Color.CYAN):
    terminal_width = get_terminal_width()
    print(f"{color}{char * terminal_width}{Color.RESET}")

# 打印带颜色的标题
def print_title(title, color=Color.BG_BLUE + Color.WHITE + Color.BOLD):
    clear_screen()
    print_separator()
    terminal_width = get_terminal_width()
    padding = max(0, (terminal_width - len(title))) // 2
    print(f"{color}{' ' * (padding - len(title)//2 - 1)}{title}{' ' * (padding - len(title)//2 + 2)}{Color.RESET}")
    print_separator()

# 打印加载动画
def print_loading(message="正在处理", duration=1.5):
    chars = ["|", "/", "-", "\\"]
    end_time = time.time() + duration
    while time.time() < end_time:
        for char in chars:
            print(f"\r{Color.YELLOW}{message}... {char}{Color.RESET}", end="", flush=True)
            time.sleep(0.1)
    print()

# 获取问题列表
def get_questions(lines):
    questions = []
    for line in lines:
        line = line.strip()
        if line.startswith(('a.', 'b.', 'c.', 'd.', 'e.', 'f.', 'g.', 'h.', 'i.', 'j.', 'k.', 'l.', 'm.', 'n.', 'o.', 'p.', 'q.', 'r.', 's.', 't.', 'u.', 'v.', 'w.', 'x.', 'y.', 'z.')):
            questions.append(line)
    return questions

# 读取问题文件
def read_questions_file(file_name):
    current_dir = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(current_dir, file_name)
    
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            question_lines = file.readlines()

        questions = get_questions(question_lines)
        return questions
    
    except FileNotFoundError:
        print(f"{Color.RED}ERROR: can not find file '{file_path}'{Color.RESET}")
        return None
    except Exception as e:
        print(f"{Color.RED}ERROR: read file '{file_path}' error: {e}{Color.RESET}")
        return None

# 打印问题卡片
def print_question_card(question):
    print_separator('=', Color.GREEN)
    print(f"{Color.BOLD}{Color.MAGENTA}问题 :{Color.RESET}")
    print_separator()
    
    # 格式化问题文本，确保每行不超过指定宽度
    max_width = 58
    words = question.split(' ')
    line = []
    for word in words:
        if len(' '.join(line + [word])) <= max_width:
            line.append(word)
        else:
            print(f"{Color.WHITE}{' '.join(line).ljust(max_width)}{Color.RESET}")
            line = [word]
    if line:
        print(f"{Color.WHITE}{' '.join(line).ljust(max_width)}{Color.RESET}")
    
    print_separator('=', Color.GREEN)

# 清除单行
def clear_line():
    terminal_width = get_terminal_width()
    print(' ' * terminal_width, end='\r')

# 隐藏光标
def hide_cursor():
    print(Color.HIDE_CURSOR, end='', flush=True)

# 显示光标
def show_cursor():
    print(Color.SHOW_CURSOR, end='', flush=True)

# 等待按键输入（跨平台）
def get_key():
    if WINDOWS:
        return msvcrt.getch().decode('utf-8')
    else:
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(sys.stdin.fileno())
            ch = sys.stdin.read(1)
            # 检测特殊键
            if ch == '\x1b':  # ESC 字符，特殊键的开始
                next1, next2 = sys.stdin.read(1), sys.stdin.read(1)
                if next1 == '[':
                    if next2 == 'A':
                        return 'up'
                    elif next2 == 'B':
                        return 'down'
                    elif next2 == 'C':
                        return 'right'
                    elif next2 == 'D':
                        return 'left'
            return ch
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)

# 显示菜单并处理光标选择
def display_menu(title, menu_items):
    terminal_width = get_terminal_width()
    padding = max(0, (terminal_width - len(title))) // 2
    current_selection = 0
    
    hide_cursor()
    try:
        clear_screen()
        while True:
            print_title(" 问题随机选择器")
            
            # 打印菜单标题
            print(f"{Color.BOLD}{Color.YELLOW}{'=' * (padding - len(title) + 1)}{title}{'=' * (padding - len(title) + 3)}{Color.RESET}\n")
            
            # 打印菜单项
            for i, item in enumerate(menu_items):
                if i == current_selection:
                    # 选中的项目
                    print(f"{Color.BG_BLUE}{Color.WHITE}  {item.text}{Color.RESET}")
                else:
                    print(f"  {item.text}")
            
            print(f"\n{Color.CYAN}使用上下键选择,回车键确认,ESC键返回{Color.RESET}")
            
            # 获取用户输入
            key = get_key()
            
            if key == 'up' or key == 'w':
                current_selection = (current_selection - 1) % len(menu_items)
            elif key == 'down' or key == 's':
                current_selection = (current_selection + 1) % len(menu_items)
            elif key == '\r' or key == '\n' or key == ' ':
                # 回车键选择
                selected_item = menu_items[current_selection]
                if selected_item.submenu:
                    # 如果有子菜单，显示子菜单
                    display_menu(selected_item.text, selected_item.submenu)
                elif selected_item.action:
                    # 如果有动作，执行动作
                    show_cursor()  # 显示光标
                    selected_item.action()
                    hide_cursor()  # 隐藏光标
            elif key == '\x1b':  # ESC键返回
                break
    finally:
        show_cursor()  # 显示光标

# 加载问题
def load_questions(file_name):
    print_loading("正在加载问题库...")
    questions = read_questions_file(file_name)
    
    if not questions:
        show_cursor()
        print(f"{Color.RED}\n无法继续,按回车键退出...{Color.RESET}")
        input()
        exit(1)
    
    total_questions = len(questions)
    print(f"{Color.GREEN}成功加载 {total_questions} 个问题！{Color.RESET}\n")
    for question in questions:
        print(question)
    input(f"{Color.CYAN}\n按任意键继续...{Color.RESET}")
    return questions

# 随机选择问题功能
def random_question_selection(questions, available_questions):
    clear_line()
    print_title(" 问题随机选择器")
    print_loading("正在随机选择问题")

    if not available_questions:
        available_questions.extend(questions)
        random.shuffle(available_questions)
    random_question = random.choice(available_questions)
    available_questions.remove(random_question)
    print_question_card(random_question)
    show_cursor()  # 显示光标
    input(f"{Color.CYAN}\n按回车键继续...{Color.RESET}")

# 退出程序功能
def exit_program():
    show_cursor()  # 显示光标
    print(f"{Color.RED}退出程序...{Color.RESET}")
    time.sleep(0.5)
    clear_screen()
    exit(0)

def main(file_name):
    print_title(" 随机问题选择器")
    
    # 加载问题
    questions = load_questions(file_name)
    
    available_questions = [];

    main_menu = [
        MenuItem("随机问题", action=lambda: random_question_selection(questions, available_questions)),
        MenuItem("退出程序", action=exit_program)
    ]
    
    # 显示主菜单
    display_menu("主菜单", main_menu)

if __name__ == "__main__":

    question_file = sys.argv[1]

    main(question_file)

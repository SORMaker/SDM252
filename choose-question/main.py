#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import random

def get_questions(lines):
    questions = []
    for line in lines:
        line = line.strip()
        if line.startswith(('a.', 'b.', 'c.', 'd.', 'e.', 'f.', 'g.', 'h.', 'i.', 'j.', 'k.', 'l.', 'm.', 'n.', 'o.', 'p.', 'q.', 'r.', 's.', 't.', 'u.', 'v.', 'w.', 'x.', 'y.', 'z.')):
            questions.append(line)
    return questions

def read_questions_file():
    current_dir = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(current_dir, 'week4.txt')
    
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            question_lines = file.readlines()

        questions = get_questions(question_lines)

        return questions
    
    except FileNotFoundError:
        print(f"错误: 找不到文件 '{file_path}'")
        return None
    except Exception as e:
        print(f"读取文件时发生错误: {e}")
        return None



if __name__ == "__main__":
    questions = read_questions_file()
    while True:
        start = input("是否开始选择问题❓: ")
        random_question = random.choice(questions)
        print("随机选择的问题:\n", random_question)
            

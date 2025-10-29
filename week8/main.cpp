#include <iostream>

class Log
{
    public:
        enum Level{
            LevelError = 0, LevelWarning, LevelInfo
        };
    private:
        Level m_LogLevel = LevelInfo;
    public:
        Log(Level level){
            std::cout << "Created Log! " << std::endl;
            m_LogLevel = level;
        }

        ~Log(){
            std::cout << "Destoryed Log! " << std::endl;
        }

        void SetLevel(Level level){
            m_LogLevel = level;
        }

        void Error(const char* message){
            if (m_LogLevel >= LevelError){
                std::cout << "[ERROR]: " << message << std::endl;
            }
        }

        void Warn(const char* message){
            if (m_LogLevel >= LevelWarning){
                std::cout << "[WARNING]: " << message << std::endl;
            }
        }

        void Info(const char* message){
            if (m_LogLevel >= LevelInfo){
                std::cout << "[INFO]: " << message << std::endl;
            }
        }
};

int main(){
    Log log(Log::LevelWarning);
    log.Info("Hello");
    log.Warn("Hello");
    log.Error("Hello");
    log.SetLevel(Log::LevelError);
    log.Info("Hello");
    log.Warn("Hello");
    log.Error("Hello");
    return 0;
}
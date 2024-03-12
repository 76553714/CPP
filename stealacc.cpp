#include <iostream>
#include <string>

class SteamAccount {
private:
    std::string username;
    std::string password;
    bool isLogged;
    bool hasTwoFactorAuth;

public:
    SteamAccount(std::string uname, std::string pwd) : username(uname), password(pwd), isLogged(false), hasTwoFactorAuth(false) {}

    void login(std::string uname, std::string pwd) {
        if (uname == username && pwd == password) {
            isLogged = true;
            std::cout << "登录成功！" << std::endl;
            checkForSuspiciousActivity();
        } else {
            std::cout << "用户名或密码错误！" << std::endl;
        }
    }

    void checkForSuspiciousActivity() {
        if (!isLogged) {
            std::cout << "账户未登录！" << std::endl;
            return;
        }

        // 在这里实现检测异常登录的逻辑
        // 可以检查登录地点、登录时间等因素来判断是否异常登录

        std::cout << "检测异常登录..." << std::endl;
        std::cout << "如果发现异常登录，将会发送警报并采取相应措施。" << std::endl;
    }

    void enableTwoFactorAuth() {
        hasTwoFactorAuth = true;
        std::cout << "双重身份验证已启用。" << std::endl;
    }

    bool isLoggedIn() const {
        return isLogged;
    }
};

int main() {
    // 创建一个Steam账户对象
    SteamAccount mySteamAccount("myusername", "mypassword");

    // 模拟登录
    mySteamAccount.login("myusername", "mypassword");

    // 如果登录成功，检测异常登录并启用双重身份验证
    if (mySteamAccount.isLoggedIn()) {
        mySteamAccount.checkForSuspiciousActivity();
        mySteamAccount.enableTwoFactorAuth();
    }

    return 0;
}

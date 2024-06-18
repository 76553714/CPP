#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 定義使用者結構，存儲嘗試登錄的使用者信息
struct User {
    string username;
    string password;
};

// 記錄嘗試登錄的使用者信息到日誌文件
void logAttempt(const User& user) {
    ofstream logfile;
    logfile.open("login_attempts.log", ios::app); // 打開日誌文件並追加寫入
    if (logfile.is_open()) {
        logfile << "嘗試登錄：" << user.username << " 密碼：" << user.password << endl;
        logfile.close();
    } else {
        cout << "無法打開日誌文件！" << endl;
    }
}

// 模擬數據庫登錄驗證，實際上始終返回假
bool authenticate(const User& user) {
    // 記錄嘗試登錄的使用者信息到日誌文件
    logAttempt(user);
    // 始終返回假，模擬登錄失敗
    return false;
}

int main() {
    // 提示使用者輸入使用者名稱和密碼
    cout << "請輸入使用者名稱：";
    string username;
    cin >> username;
    cout << "請輸入密碼：";
    string password;
    cin >> password;

    // 創建使用者對象
    User user = {username, password};

    // 調用數據庫登錄驗證函數
    if (authenticate(user)) {
        cout << "登錄成功！" << endl;
    } else {
        cout << "登錄失敗，請重試。" << endl;
    }

    return 0;
}

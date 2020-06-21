// singlyLinkedList.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <stdbool.h>
#include <string>

using namespace std;

typedef struct packet //def packet
{
    bool busy = false;
    int flag = 0;

    int from = 0;
    int to = 0;

    string message;

};

typedef struct device  //def device
{
    int id;

    packet *p;
    device *nextDevice;

    int sentFrom;
    string recMessage;
};


void addMessage(device* from, int to, string message) {
    struct packet packet1;
    packet1.busy = true;
    packet1.flag += 1;
    packet1.from = from->id;
    packet1.to = to;
    packet1.message = message;
    from->p = &packet1;
}

void sendMessage(device* from, int to, string message) {
    addMessage(from, to, message);

}

void showMessage(device* selectedDevice) {
    packet* packet = selectedDevice->p;
    string message;
    message = packet->message;
    std::cout << "Message:\n";
    std::cout << message<<"\n";
    

}

int main()
{
    
    //make devices
    struct device device1;
    struct device device2;
    struct device device3;

    device* pDevice1 = &device1;
    device* pDevice2 = &device2;
    device* pDevice3 = &device3;

    pDevice1->id = 1;
    pDevice2->id = 2;
    pDevice3->id = 3;

    

    pDevice1 -> nextDevice = &device2;
    pDevice2->nextDevice = &device3;
    pDevice3->nextDevice = NULL;

    int selectedDevice, ToDevice;
    device *pSelecteDvice;
    string message;

    std::cout << "From:\n";
    std::cin >> selectedDevice;

    std::cout << "To:\n";
    std::cin >> ToDevice;

    std::cout << "Message:\n";
    std::cin >> message;

    if (selectedDevice == 1) {
        pSelecteDvice = &device1; 
    }else if (selectedDevice == 2){
        pSelecteDvice = &device2;
    }
    else{
        pSelecteDvice = &device3;
    }

    addMessage(pSelecteDvice, ToDevice, message);
    showMessage(pSelecteDvice);



    std::cout << "From:\n";
    std::cout << selectedDevice << "\n";
    

    

    std::cout << "Hello World!\n";
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

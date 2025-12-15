#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count; // HP 포션 개수를 count 값으로 설정
    *p_MPPotion = count; //MP 포션 개수를 count 값으로 설정
}

int main() {
    const int SIZE = 4; // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    int stat[SIZE] = { 0 };

    while (1) { //HP, MP를 50 이상으로 받을때까지 반복
        cout << "HP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50) //HP, MP가 50보다 크면 반복문 탈출
            break;

        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (1) { //공격력, 방어력을 0 초과로 받을때까지 반복
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0) //공격력, 방어력이 0보다 크면 반복문 탈출
            break;

        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    int HPPotion = 0; // HP 포션 개수
    int MPPotion = 0; // MP 포션 개수

    setPotion(5, &HPPotion, &MPPotion); //HP, MP 포션 각각 5개 지급

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP UP" << endl;
    cout << "2. MP UP" << endl;
    cout << "3. 공격력 UP" << endl;
    cout << "4. 방어력 UP" << endl;
    cout << "5, 현재 능력치" << endl;
    cout << "6. Level UP" << endl;
    cout << "0, 나가기" << endl;

    int choice = 0; // 메뉴 선택 변수

    while (1) { // 메뉴 반복문 실행
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        if (choice == 0) { // 0 입력 시 프로그램 종료
            cout << "프로그램을 종료합니다." << endl;
            break; // 프로그램 종료
        }

        switch (choice) { // 선택한 메뉴에 따른 동작 수행

        case 1:
            if (HPPotion <= 0) { // HP 포션이 없을 때
                cout << "포션이 부족합니다." << endl;
                break;
            }
            stat[0] += 20; // HP 20 증가
            HPPotion--; // HP 포션 1개 차감
            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 HP: " << stat[0] << endl;
            cout << "남은 포션 수: " << HPPotion << endl;
            break; // HP 포션 사용 후 탈출

        case 2:
            if (MPPotion <= 0) { // MP 포션이 없을 때
                cout << "포션이 부족합니다." << endl;
                break;
            }
            stat[1] += 20; // MP 20 증가
            MPPotion--; // MP 포션 1개 차감
            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "현재 MP: " << stat[1] << endl;
            cout << "남은 포션 수: " << MPPotion << endl;
            break; // MP 포션 사용 후 탈출

        case 3:
            stat[2] *= 2; // 공격력 2배 증가
            cout << "* 공격력이 2배로 증가되었습니다." << endl;
            cout << "현재 공격력: " << stat[2] << endl;
            break; // 공격력 2배 증가 후 탈출

        case 4:
            stat[3] *= 2; // 방어력 2배 증가
            cout << "* 방어력이 2배로 증가되었습니다." << endl;
            cout << "현재 방어력: " << stat[3] << endl;
            break; // 방어력 2배 증가 후 탈출

        case 5:
            cout << "* HP : " << stat[0]
                << ", MP : " << stat[1]
                << ", 공격력 : " << stat[2]
                << ", 방어력 : " << stat[3] << endl;
            break; // 스탯 출력

        case 6:
            setPotion(5, &HPPotion, &MPPotion); // HP, MP 포션 각각 5개 지급
            cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
            cout << "남은 HP/MP 포션 수 : "
                << HPPotion << "/" << MPPotion << endl;
            break; // 포션 지급

        default: // 잘못된 값 입력 시
            cout << "다시 입력해주세요." << endl;
        }
    }

    return 0; // 프로그램 종료
}


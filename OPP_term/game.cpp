#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <mutex>
#include <iomanip>

const int ROWS = 10;
const int COLS = 4;
using namespace std;

class block
{
    string name;  // 제거해야할 이름을 말합니다.
    int speed;    // 떨어지는 속도를 말합니다.
    int line;     // 몇번째 줄인지를 말합니다.
    bool onboard; // 현재 판에 올라가 한번만 움직였는지를 판단합니다.

public:
    block()
    {
        name = "";
        speed = 0;
    }
    block(string Iname, int Ispeed)
    {
        name = Iname;
        speed = Ispeed;
        onboard = true;
    }
    string getName()
    {
        return name;
    }
    int getSpeed()
    {
        return speed;
    }
    int getLine()
    {
        return line;
    }
    int getOnBoard()
    {
        return onboard;
    }
    void setonBoard(bool input)
    {
        onboard = input;
    }
    void setSpeed()
    {
        speed = rand() % 3 + 1;
        
    }

    bool operator==(const block &other) const
    {
        return name == other.name && speed == other.speed;
    }
};

mutex mtx;

// 함수 선언
void generateRandomWords(vector<vector<string>> &words);
void printGameBoard(const vector<vector<string>> &words);
void moveWordsDown(vector<vector<string>> &words);
void gameThread(vector<vector<string>> &words);

string englishWords[] = {"Potato", "Apple", "Banana", "Watermelon", "Orange", "Strawberry", "Melon", "Carrot", "Blueberry", "DragonFruit"};
string specialWords[] = {"!", "@", "#", "$", "%", "^", "&", "*", "(", ")"};
string number[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
vector<block> boxes;
int MAX_LINE = 4;

// Decorator Design Pattern
class StringDecorator
{
public:
    virtual void decorate(string &str) = 0;
    virtual ~StringDecorator(){};
};

class AlphabetDecorator : public StringDecorator
{
public:
    void decorate(string &str) override
    {
        int randomNumber = rand() % 10;
        str = str + englishWords[randomNumber];
    }
    ~AlphabetDecorator() { delete this; };
};

class NumberDecorator : public StringDecorator
{
public:
    void decorate(string &str) override
    {
        int randomNumber = rand() % 10;
        str = str + number[randomNumber];
    }
    ~NumberDecorator() { delete this; };
};

class SpecialCharDecorator : public StringDecorator
{
public:
    void decorate(string &str) override
    {
        int randomNumber = rand() % 10;
        str = str + specialWords[randomNumber];
    }

    ~SpecialCharDecorator()
    {
        delete this;
    };
};

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<vector<string>> words(ROWS, vector<string>(COLS, ""));

    // 초기화
    generateRandomWords(words);
    printGameBoard(words);

    // 게임 쓰레드 시작
    thread game(gameThread, ref(words));

    // 메인 쓰레드에서 사용자 입력 처리
    string userInput;
    while (true)
    {
        cin >> userInput;
        {
            lock_guard<mutex> lock(mtx);

            // 입력한 단어가 배열에 있는지 확인하고 제거
            for (int i = 0; i < ROWS; ++i)
            {
                for (int j = 0; j < COLS; ++j)
                {
                    if (words[i][j] == userInput)
                    {
                        vector<block> newBoxes;
                        for (int i = 0; i < boxes.size(); i++)
                        {
                            if (userInput != boxes[i].getName())
                            {
                                newBoxes.push_back(boxes[i]);
                            }
                        }
                        boxes = newBoxes;
                        words[i][j] = "";
                    }
                }
            }
        }

        // 모든 단어가 제거되었는지 확인
        bool allWordsCleared = true;
        for (const auto &row : words)
        {
            for (const auto &word : row)
            {
                if (!word.empty())
                {
                    allWordsCleared = false;
                    break;
                }
            }
            if (!allWordsCleared)
                break;
        }

        if (allWordsCleared)
        {
            cout << "게임 클리어!" << endl;
            exit(0);
            break;
        }
    }

    // 게임 쓰레드 종료
    game.join();

    return 0;
}

void generateRandomWords(vector<vector<string>> &words)
{

    vector<StringDecorator *> decorators;

    decorators.push_back(new AlphabetDecorator);
    decorators.push_back(new NumberDecorator);
    decorators.push_back(new SpecialCharDecorator);

    int targetSize = rand() % 4 + 1;

    for (int i = 0; i < targetSize; i++)
    {
        string targetString = "";
        for (int i = 0; i < 3; i++) // 문자열 옵션에 따라 랜덤 생성.
        {
            decorators[i]->decorate(targetString);
        }
        int speed = rand() % 3 + 1;
        boxes.push_back(block(targetString, speed));
    }
    int canStart = 0;
    while (canStart != targetSize)
    {
        int randomPosition = rand() % 3;

        if (words[0][randomPosition] == "")
        {
            words[0][randomPosition] = boxes[canStart].getName();
            canStart++;
        }
    }

    return;
}

void printGameBoard(const vector<vector<string>> &words)
{
    system("clear"); // 콘솔을 지우는 명령어 (윈도우의 경우 "cls")

    int i = 10;

    for (const auto &row : words)
    {

        cout << i << "층";
        for (const auto &word : row)
        {
            cout << setw(15) << word; // 각 열의 폭을 15로 설정 (필요에 따라 조절)
        }
        i--;
        cout << '\n';
    }
    cout << "------------------------------------" << endl;
    cout << "입력하세요 :" << endl;
}

void moveWordsDown(vector<vector<string>> &words)
{
    {
        lock_guard<mutex> lock(mtx);
        int isRemain = 0;
        int deleteIndex = 0;
        vector<block> newBoxes;

        // 맨 위 행부터 시작하여 아래로 내리며 단어 이동
        for (int i = 0; i < ROWS; ++i)
        {
            if (isRemain > boxes.size())
            {
                break;
            }
            for (int j = 0; j < COLS; ++j)
            {

                if (words[i][j] != "")
                {

                    int movement = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        if (words[i][j] == boxes[k].getName() && boxes[k].getOnBoard())
                        {
                            movement = boxes[k].getSpeed();
                            boxes[k].setonBoard(false);
                            isRemain++;
                            deleteIndex = k;
                            break;
                        }
                    }

                    // 아래로 내릴 위치 계산
                    if (isRemain <= boxes.size())
                    {
                        if (isRemain == boxes.size())
                        {
                            isRemain++;
                        }

                        int nextRow = i + movement;

                        if (nextRow >= ROWS)
                        { // 범위를 넘어가면
                            int temp;
                            for (int z = 0; z < boxes.size(); z++)
                            {
                                if (words[i][j] == boxes[z].getName())
                                {
                                    temp = z;
                                    break;
                                }
                            }

                            for (int l = 0; l < boxes.size(); l++)
                            {
                                if (words[i][j] != boxes[l].getName())
                                {
                                    newBoxes.push_back(boxes[l]);
                                }
                            }
                            words[i][j] = "";
                            boxes = newBoxes;
                        }
                        else
                        {
                            words[nextRow][j] = words[i][j];
                            words[i][j] = "";
                            newBoxes.push_back(boxes[deleteIndex]);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < newBoxes.size(); i++)
        {
            newBoxes[i].setonBoard(true);
            newBoxes[i].setSpeed(); // 속도 랜덤으로 조정.
        }
        boxes = newBoxes;
    }
    printGameBoard(words);
}

void gameThread(vector<vector<string>> &words)
{
    while (true)
    {
        this_thread::sleep_for(chrono::seconds(7)); // 10초 대기
        moveWordsDown(words);
    }
}

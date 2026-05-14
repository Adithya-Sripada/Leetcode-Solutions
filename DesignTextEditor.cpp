#include <iostream>
#include <string>
using namespace std;
struct TextNode {
    char data;
    TextNode* previous;
    TextNode* next;
    TextNode(char x) : data(x), previous(nullptr), next(nullptr) {}
};

class TextEditor {
private:
    TextNode* cursor;
public:
    TextEditor() {
        cursor = new TextNode('\0');;
    }

    void addText(string text) {
        for (char c : text) {
            TextNode* n = new TextNode(c);
            // Insert n immediately before cursor
            n->next = cursor;
            n->previous = cursor->previous;
            if (cursor->previous) cursor->previous->next = n;
            cursor->previous = n;
        }
    }

    int deleteText(int k) {
        int count = 0;
        TextNode* temp;
        while(cursor->previous && count < k) {
            temp = cursor->previous;
            cursor->previous = temp->previous;
            if(temp->previous) temp->previous->next = cursor;
            delete temp;
            count++;
        }
        return count;
    }

    string cursorLeft(int k) {
        int count = 0;
        TextNode* temp;
        while(cursor->previous && count < k) {
            temp = cursor->previous;
            if(cursor->next) cursor->next->previous = temp;
            temp->next = cursor->next;

            cursor->next = temp;
            cursor->previous = temp->previous;
            if(temp->previous) temp->previous->next = cursor->next;
            temp->previous = cursor;
            count++;
        }
        temp = cursor->previous;
        string s = "";
        count = 0;
        while(temp && count < 10) {
            s += temp->data;
            temp = temp->previous;
            count++;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    string cursorRight(int k) {
        int count = 0;
        TextNode* temp;
        while(cursor->next && count < k) {
            temp = cursor->next;
            if(cursor->previous) cursor->previous->next = temp;
            temp->previous = cursor->previous;

            cursor->previous = temp;
            cursor->next = temp->next;
            if(temp->next) temp->next->previous = cursor->previous;
            temp->next = cursor;
            count++;
        }
        temp = cursor->previous;
        string s = "";
        count = 0;
        while(temp && count < 10) {
            s += temp->data;
            temp = temp->previous;
            count++;
        }
        std::reverse(s.begin(), s.end());
        return s;
    }

    bool isEmpty() {
        return cursor == nullptr;
    }
};
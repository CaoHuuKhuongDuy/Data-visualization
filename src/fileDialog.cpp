#include "fileDialog.h"

string openFileDialog(HWND owner)
{
    OPENFILENAMEA ofn; 
    char szFile[260] = { 0 };
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = owner;
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
    if (GetOpenFileNameA(&ofn)) return szFile;
    return "";
}

bool validate(string s) {
    if (s.size() > 2) return false;
    for (int i = 0; i < s.size(); i++)
      if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

void import(RenderWindow &window, int val[], int &numNode, int maximumNode)
{
    maximumNode--;
    string filePath = openFileDialog(window.getSystemHandle());
    if (filePath.empty()) return;
    ifstream ci(filePath);
    numNode = 0;
    string s;
    while (numNode <= maximumNode && !ci.eof()) {
        ci >> s;
        if (validate(s)) val[++numNode] = stoi(s);
    }
    ci.close();
}

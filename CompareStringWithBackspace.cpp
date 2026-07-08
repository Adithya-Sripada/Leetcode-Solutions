bool backspaceCompare(string s, string t) {
    string news = "";
    string newt = "";
    for(char c : s) {
        if(c == '#') {
            if(!news.empty()) news.pop_back();
            continue;
        }
        news.push_back(c);
    }
    for(char c : t) {
        if(c == '#') {
            if(!newt.empty()) newt.pop_back();
            continue;
        }
        newt.push_back(c);
    }
    return news == newt;
}

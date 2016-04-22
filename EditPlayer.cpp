void EditPlayer(){
    /*Allows the player data to be edited*/
    string answer;
    map<string, Player>::iterator itr;

    Player p;

    cout << "Edit player? (YES or NO)" << endl;
    cin >> answer;
    if ((answer == "YES")||(answer == "yes")||("Yes")){
        cout << "Player name?" << endl;
        cin >> p.name;
        itr = m.find(p.name);
        m.erase (itr);
        cout << "Please enter new information." << endl;
        AddPlayer();
        cout << "Player Information Changed." << endl;

    } else {
        cout << "No Changes Made." << endl;
    }
}

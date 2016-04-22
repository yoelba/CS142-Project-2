int NewSeason(){
    /*Makes file, deletes data in file if
    there is already data in there*/
    ofstream outfile;
    string file_name;
    char choice;

    m.empty();
        if (m.empty() != true){
            m.clear();
            cout << "Map Cleared" << endl;
        } else {
            cout << "Map Empty" << endl;
        }

    cout << "Do you wish to delete previous season's file? (Y/N)";
    cin >> choice;

    if ((choice = 'Y') || (choice = 'y')){
        std::remove("Season.txt");
    }

    outfile.open ("Season.txt");
        for (map<string, Player> :: iterator itr = m.begin(); itr != m.end(); ++itr){
            outfile << itr -> first << endl << itr -> second.b_year << endl << itr -> second.category << endl << itr -> second.registered << endl;
        }

    if (!outfile.is_open()){
        cout << "File could not open." << endl;
    }

    return 0;
    }

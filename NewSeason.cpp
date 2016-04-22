int NewSeason(){
    /*Makes file, deletes data in file if
    user wants it deleted*/
    ofstream outfile;
    char choice;
    string string_year;

    m.empty();
        if (m.empty() != true){
            m.clear();
        }

    cout << "Do you wish to delete previous season's file? (Y/N) ";
    cin >> choice;

    if ((choice == 'N') || (choice == 'n')){
        return 0;
    } else if ((choice == 'Y') || (choice == 'y')){
        std::remove("Season.txt");
        cout << "Year: " << endl;
        cin >> string_year;

        for(int i = 0; i < string_year.length(); i++){
            while (!isdigit(string_year.at(i))){
                cout << "Year: " << endl;
                cin >> string_year;
                i=0;
            }
        }
        curr_year = atoi(string_year.c_str());


        outfile.open ("Season.txt");

        if (!outfile.is_open()){
            cout << "File could not open." << endl;
        }

        return 1;
        }
}

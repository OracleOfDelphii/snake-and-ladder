#include "header.h"

using namespace std;
// ANSI escape sequence
const string store = "\033[u" , restore = "\033[s";
const string up = "\033[A";
const string EraseToEnd = "\033[K";
const string Green = "\u001b[32m";
const string Yellow = "\u001b[33m";
const string Bold = "\u001b[1m";
const string Red = "\u001b[31;1m";
const string Reset_Terminal = "\033c";
const string RESET = "\u001b[0m";
int main()
{
    int nrows , snake_count ,ladder_count;
    int num_players = 2;
    data::player player;
    data::board board;
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> dice(1, 6);
    std::uniform_int_distribution<int> colorpallete(30, 37);
    std::vector <int> dist(nrows*nrows);
    vector <vector <int>> adj(nrows*nrows);
    adj.resize(nrows * nrows);
    map <int , string> graphical;
    Mix_Chunk *sound = NULL;
    for(int i = 0 ; i<nrows * nrows ; i++)
    {
        dist.push_back(0);
    }

    SDL_Init(SDL_INIT_VIDEO);
    int audio_rate = 22050;
    Uint16 audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
    }
    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
        printf("Unable to initialize audio: %s\n", Mix_GetError());
    }
      QString str = QDir::currentPath() ;
            std::string self_path = str.
                    toUtf8().constData();
            string spath =  self_path + "/sound/main.mp3";
            string soundpath = self_path + "/sound/roll.wav";
    const char* MY_COOL_MP3 = spath.c_str();

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
      Mix_Music *music = Mix_LoadMUS(MY_COOL_MP3);
    Mix_PlayMusic(music, -1);
    string welcome = "\e[0;33m      \n      .@''+:               ,#''#`           \n      @''''@               @''''@           \n      +''''@              `+''''@           \n      :'''''@              ;'''''@           \n      #'''''@              @'''';+           \n      @'''';:              @'''''.           \n      #''''+               #''''#           \n      .'''';@              .'''''@           \n      #'''@++++++++++++++++@'''''@           \n      @'''@''''''''''''''''@''''',           \n      @'''@''''''''''''''''@''''+           \n      +'''@@@@@@@@@@@@@@@@@+''''@           \n      :;''''@              ;;''''@           \n      @'''''@              @'''';'           \n      @''''':              @'''''`           \n      #''''+               #''''@       welcome to snake and ladder!     \n      .'''''@              ,'''''@           \n      +;''''@              #'''''#           \n      @''';;;              @''''',           \n      @'''##################''''+           \n      `+''#;'''''''''''''''''''''@           \n      ;'''#;'''''''''''''''#'''''@           \n      @'''++'''''''''''''''@''''';           \n      @''''':``````````````@''''+`           \n      #''''+               +''''@           \n      ,'''''@              :;''''@           \n      @'''''@              @'''';#           \n      @''''''              @'''''.           \n      @''''+`              #''''#           \n      +''''@              .'''''@           \n      ;;''@@@@@@@@@@@@@@@@@@;''''@";
    bool txt_slower = false;
    int delay = 3;
    for(int i = 0 ; i < (int)welcome.length()  ;i++)
    {
      string letter = welcome.substr(i,1);
      cout<<letter;
        cout.flush();
      if(!txt_slower)
      nsleep(delay);
        else
      {
          delay = 70;
       nsleep(delay);
      }
      if(letter=="w")
      {
       txt_slower=true;
      }
      if(letter=="r"){
         txt_slower = false;
         delay = 2;
      }
    }
    cout<<RESET<<restore;
    cin.get();
    cout<<Reset_Terminal;
    algorithm algorithm;
    char ToDo= 0;
    cout<<Bold;
    cout<<"new game : 0  load : 1"<<endl;
    cin>>ToDo;
    if(ToDo== '0')
    {
        cout<<"Enter the number of rows";
        cin>>nrows;
        while(nrows <=1 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Invalid Entry , try again";
            cin>>nrows;
        }
        cout<<"Enter the number of snakes";
        cin>>snake_count;
        while(snake_count<0 || snake_count>nrows*(nrows-1) - 1 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Invalid Entry , value must be between "<<0<<" and "<< nrows*(nrows-1) - 1<<endl;
            cout<<"Enter the number of snakes";
            cin>>snake_count;
            cout<<up<<'\r';
        }
        cout<<"Enter the number of Ladders";
        cin>>ladder_count;
        while(ladder_count < 0 || ladder_count >(nrows-1)*nrows - snake_count - 1 || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout<<"Invalid Entry , value must be between "<<0<<" and "<<(nrows-1)*nrows - snake_count -  1 <<endl;
            cout<<"Enter the number of ladders";
            cin>>ladder_count;
        }

        cout<<"Enter number of players";
        cin>>num_players;
        while(std::cin.fail() || num_players < 2)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Bad entry.  Try again: ";
                std::cin >>num_players;
            }

        for(int i = 0 ; i<num_players ; i++)
        {
            player.Play_Permit[i]=false;
            player.cell[i]=0;
        }

        for(int i = 0 ; i< num_players ; i++)
        {
            cout<<"Enter name of player"<<i<<" :";
            cin>>player.name[i];
        }
    }
        else{
        for(int i = 0 ; i< nrows * nrows ; i++)
        {
         dist.push_back(0);
        }

            load_game(player , board , graphical, dist, num_players , nrows,snake_count , ladder_count);
        }
       cout<<Reset_Terminal;
       cout<<"Load game : 1  save game : 2"<<endl;

       if(ToDo=='0')
       {
    make_ladder_snake(nrows , board , graphical , snake_count , ladder_count);
}

       adj.reserve(nrows*nrows);
       adj.resize(nrows*nrows);
    adj = algorithm.make_adj(board.holder , nrows);
    dist =  algorithm.bfs(0 , adj , nrows);

    while(dist[nrows*nrows-1]==0)
    {
        for(int i = 0 ; i<nrows * nrows ; i++){board.holder[i]=0;}
        for(int i = 0 ; i<nrows*nrows; i++)
        {
            for(int j = 0 ; j<nrows*nrows; j++)
            {
                adj[i][j]=0;
            }
        }
        make_ladder_snake(nrows , board , graphical , snake_count , ladder_count);
        nsleep(5);
        adj = algorithm.make_adj(board.holder , nrows);
        dist = algorithm.bfs(0 , adj , nrows);
    }
    cout<<"Path detected :"<<dist[nrows*nrows-1]<<'\n';

    if(make_table(nrows)==true)
    {
        // save cursor position , to Restore store
        cout<<restore;
        initialize_table(-1 , nrows, graphical , board , player ,  5  , 0 , nrows);
        int random = 0 , prev_cell = 0 , winner  = 0 ;
        bool win = false;
        char ch;
        while(!win)
        {
            cout<<(store + restore);
            for(int i = 0 ; i< num_players ; i++)
            {
                cout<<(store + restore);
                if(ch=='\n')
                {
                    PUSH_FORWARD(nrows);
                    string color = "\u001b[";
                    color += std::to_string(colorpallete(generator))+";1m";
                cout<<player.name[i]<<RESET<<": press enter to proceed "<<'\n';
                }
                else{
                cout<<endl;
                }
                 cin.get();
                ch =  cin.get();
                switch (ch)
                {
                case '\n':
                    cout<<(store + restore);
                    initialize_table(-1 , nrows, graphical , board , player , 0 , (int)ceil(prev_cell/nrows) , (int)ceil(prev_cell/nrows));
                    sound = Mix_LoadWAV(soundpath.c_str());
                    Mix_PlayChannel(-1, sound, 0);
                    cout<<(store + restore);
                    PUSH_FORWARD(nrows);
                    for(int i = 0 ; i<2*nrows+5 ; i++)
                    {
                        cout<<EraseToEnd;
                        cout<<up;
                    }
                    random = (int)dice(generator);
                    if(player.Play_Permit[i]==true)
                    {
                        if(player.cell[i]<=nrows*nrows-random){
                            player.cell[i]+=random;
                        }
                        if(player.cell[i]==nrows*nrows)
                        {
                            win=true;
                            break;
                        }
                        if(board.holder[player.cell[i]]!=0){
                            player.cell[i]=board.holder[player.cell[i]];
                            sound = Mix_LoadWAV(soundpath.c_str());
                            Mix_PlayChannel(-1, sound, 0);
                        }
                        string color = "\u001b[";
                        color += std::to_string(colorpallete(generator));
                        color+=";1m";
                        cout<<(store + restore);
                        initialize_table(i , nrows, graphical , board , player , 0 , (int)ceil(player.cell[i]/nrows) , (int)ceil(player.cell[i]/nrows));
                        prev_cell = player.cell[i];
                        PUSH_FORWARD(nrows);
                        cout<<"dice for "<<color<<player.name[i]<<RESET<<" "<<random<<" "<<'\n';
                        PUSH_FORWARD(nrows);
                        cout<<color<<player.name[i]<<RESET<<" is in Cell "<<player.cell[i]<<" "<<'\n';
                        adj = algorithm.make_adj(board.holder , nrows);
                        dist =  algorithm.bfs(player.cell[i],adj , nrows);
                        PUSH_FORWARD(nrows);
                        cout<<"Shortest path for "<<color<<player.name[i]<<RESET<<" "<<dist[nrows*nrows-1]<<'\n';
                    }
                    while(random==6)
                    {
                         cin.get();
                          ch = cin.get();
                          string color = "\u001b[";
                          color += std::to_string(colorpallete(generator));
                          color+=";1m";
                        if(ch=='\n')
                        {
                            if(player.Play_Permit[i]==false)
                            {
                                PUSH_FORWARD(nrows);
                                cout<<color<<player.name[i]<<RESET<<" is in the game!"<<'\n';
                            }
                            cout<<(store + restore);

                            PUSH_FORWARD(nrows);
                            cout<<color<<player.name[i]<<RESET<<": Press enter to proceed "<<'\n';


                            player.Play_Permit[i]=true;
                        }
                        else if(ch=='1')
                        {
                            load_game(player , board , graphical, dist, num_players , nrows,snake_count , ladder_count);
                        }
                        else if(ch=='2')
                        {
                          save_game(player , board , graphical , dist , num_players , nrows , snake_count , ladder_count);
                        }
                        cin.get();
                        ch = cin.get();
                        if(ch=='\n')
                        {
                            cout<<(store + restore);
                            initialize_table(-1 , nrows, graphical , board , player, 0 , (int)ceil(prev_cell/nrows) , (int)ceil(prev_cell/nrows));
                            sound = Mix_LoadWAV("/home/ali/Music/roll.wav");
                            Mix_PlayChannel(-1, sound, 0);
                            cout<<(store + restore);
                            PUSH_FORWARD(nrows);
                            for(int i = 0 ; i<2*nrows+5 ; i++)
                            {
                                cout<<EraseToEnd;
                                cout<<up;
                            }
                            random = (int)dice(generator);
                            cout<<'\n';
                            PUSH_FORWARD(nrows);
                            cout<<"dice for "<<color<<player.name[i]<<RESET<<" "<<random<<" "<<'\n';
                            if(player.cell[i]<=nrows*nrows-random){
                                player.cell[i]+=random;
                            }
                            if(player.cell[i]==nrows*nrows)
                            {
                                win=true;
                                winner=i;
                            }
                            if(board.holder[player.cell[i]]!=0){
                                player.cell[i]=board.holder[player.cell[i]];
                            }
                            cout<<(store + restore);
                            initialize_table(i , nrows, graphical , board , player, 0 , (int)ceil(player.cell[i]/nrows) , (int)ceil(player.cell[i]/nrows));
                            prev_cell = player.cell[i];
                            PUSH_FORWARD(nrows);
                            cout<<color<<color<<player.name[i]<<RESET<<RESET<<" is in Cell "<<player.cell[i]<<" "<<'\n';
                            dist =  algorithm.bfs(player.cell[i],adj , nrows);
                            PUSH_FORWARD(nrows);
                            cout<<"Shortest path for "<<color<<player.name[i]<<RESET<<" "<<dist[nrows*nrows-1]<<'\n';

                        }
                        else if(ch=='1')
                        {
                            load_game(player , board , graphical, dist, num_players , nrows,snake_count , ladder_count);
                        }
                        else if(ch=='2')
                        {
                          save_game(player , board , graphical , dist , num_players , nrows , snake_count , ladder_count);
                        }
                    }
                    break;
                case '1':
                   load_game(player , board , graphical, dist, num_players , nrows,snake_count , ladder_count);

                    break;

                case '2':
                    save_game(player , board , graphical , dist , num_players , nrows , snake_count , ladder_count);
                    break;
                }

            }
        }

        // winning animation
        double r = 39;
        uniform_int_distribution <int> ANIM(5,15);
        for (double m = 1; m <= r/4; m++)
        {
            double s = 0;
            cout <<endl;
            s = sqrt(m*(2*r-m));
            for (double i = 0; i < (r-s); i++)
            {
                cout << "\033[C";
            }
            string color = "\u001b[";
            color += std::to_string(colorpallete(generator))+";1m";
            cout <<color<<player.name[winner]<<" WON!"<<RESET;
            nsleep(ANIM(generator));
            for (double i = 2*(int)(s); i > 0; i--)
            {
                string color = "\u001b[";
                color += std::to_string(colorpallete(generator))+";1m";
                cout <<color<<'_'<<RESET;
            }
            color = "\u001b[";
            color += std::to_string(colorpallete(generator))+";1m";
            cout <<color<<player.name[winner]<<" WON!"<<RESET;
        }
    }
    Mix_FreeChunk(sound);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    cin.get();
    cin.get();

}
int digit_count(int n){
    int p = 1;
    while(n>0)
    {
        n = n / 10;
        p++;
    }
    return p ;
}
void PUSH_FORWARD(int nrows)
{
    cout<<'\r';
    for(int i = 0 ; i < (float)(2+digit_count(nrows*nrows)+1)*nrows + 2 ; i++)
    {cout<<"\033[C";}
}
void initialize_table(int player_id , int nrows , map <int , string> &graphical , data::board &board , data::player player , int sleep , int from , int to)
{
    // initializing table
    int x = 0 , y = 0;
    int j = from%2 ;
    int k = 2*nrows - 1;
    // moving upward
    for(int  i = 1 ; i <= k && y<=2*to; i++)
    {
        cout<<up;
        cout<<'\r';
        y++;
        if(y<=2*from)
        {
            continue;
        }
        if(y%2==1 && y>2*from){
            for(int  i = 0 ; i < (float)(2+digit_count(nrows*nrows)+1)*nrows -1 ; i++)
            {
                if(i%(2+digit_count(nrows*nrows)+1)==0)
                {
                    cout<<"║ ";
                    x = ceil((float)i / (float)(2+digit_count(nrows*nrows)+1));
                    int cell_num = 0;
                    if(j==0){
                        cell_num = ((y-1)/2)*nrows + x + 1;
                    }
                    else{
                        cell_num = ((y-1)/2+1)*nrows - x ;
                    }
                    if(board.holder[cell_num]==0){
                        nsleep(sleep);
                        if(player.cell[player_id]!=cell_num){
                            cout<<"\u001b[34m"<<cell_num<<RESET;
                            cout.flush();
                            i+= digit_count(cell_num);
                        }
                        else{
                            cout<<Red + Bold<<"P"<<player_id<<RESET;
                            cout.flush();
                            i+= 1 + digit_count(player_id);
                        }

                    }
                    else{
                        nsleep(sleep);
                        string a = graphical[cell_num];
                        bool snake = false;
                        if((int)a[0]==76)
                        {
                            snake = true;
                        }
                        if(!snake){
                            cout<<Green + Bold<<graphical[cell_num]<<RESET;
                            cout.flush();
                        }
                        else
                        {
                            cout<<Yellow + Bold<<graphical[cell_num]<<RESET;
                            cout.flush();
                        }
                        i+= 1+digit_count(board.holder[cell_num]);

                    }
                    continue;
                }
                else{
                    cout<<' ';
                }
            }
            j=!j;
        }}
    PUSH_FORWARD(nrows);
    for(int i = 0 ; i<2*nrows+1 ; i++)
    {
        cout<<up;
    }
}
bool make_table(int n)
{
    string horizontal=" ═";
    string vertical = "║ ";
    for(int i = 0 ; i< digit_count(n*n)+1;i++)
    {
        horizontal+="═";
        vertical +=" ";
    }
    for(int j = 0 ; j < n ; j++)
    {
        nsleep(45);
        for(int i = 0 ; i <n ;i++)
        {cout<<horizontal;}
        cout<<endl;
        for(int i = 0 ; i <=n ;i++)
        {cout<<vertical;}
        cout<<endl;
    }
    for(int i = 0 ; i <n ;i++)
    {
        cout<<horizontal;
    }

    return true;
}

void make_ladder_snake(int nrows , data::board &board , map <int , string> &graphical , int snake_count , int ladder_count)
{
    // we can not have snake in first row
    // we can not have Ladder in last row
    // first cell or last cell can not be neither snake nor ladder

    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> dis(0, nrows*nrows);
    map <int , bool> snake_tale;
    map <int, bool> snake_head;
    map <int , bool> ladder_top;
    map <int, bool> ladder_bottom;

    //snakes
    for(int i = 0 ; i<nrows*nrows ; i++){snake_tale[i]=false ; snake_head[i]=false;}
    int produced_snakes = 0 ;
    for( ; produced_snakes< snake_count ; )
    {
        int  Rnd01 = dis(generator) , random2 = dis(generator);

        if ((int)ceil(Rnd01/nrows)!=1 && Rnd01 != nrows*nrows){
            if((int)ceil(random2/nrows)!=1 && random2 < Rnd01){
                if(!(snake_head[Rnd01]) && !(snake_tale[Rnd01]) && !snake_head[random2]){
                    produced_snakes++;
                    snake_head[Rnd01]=true;
                    snake_tale[random2]=true;
                    graphical[Rnd01]='S'+std::to_string(random2);
                    board.holder[Rnd01]= random2 ;

                }
            }
        }
    }

    // ladders
    for(int i = 0 ; i<nrows*nrows ; i++){ladder_top[i]=false ; ladder_bottom[i]=false;}
    int produced_ladders = 0 ;
    for( ; produced_ladders< ladder_count ; )
    {
        int  Rnd01 = dis(generator);
        int random2 = dis(generator);

        if(snake_tale[Rnd01]==false && snake_head[Rnd01]==false && Rnd01 !=0 )
        {
            if (ceil(random2/nrows)!=nrows && random2 != nrows*nrows-1){
                if(snake_tale[random2]==false && snake_head[random2]==false){
                    if(snake_tale[Rnd01]==false && snake_head[Rnd01] == false)
                        if(!(ladder_top[Rnd01]) && !(ladder_bottom[Rnd01]) && !ladder_top[random2]){
                            if(random2 > Rnd01 && ceil(random2/nrows)!=nrows && random2 != nrows*nrows-1){
                                produced_ladders++;
                                ladder_top[Rnd01]=true;
                                ladder_bottom[random2]=true;
                                graphical[Rnd01]='L'+std::to_string(random2);
                                board.holder[Rnd01]= random2 ;
                            }
                        }
                }
            }
        }
    }
}

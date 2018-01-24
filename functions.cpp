#include "header.h"
#include <sstream>
using namespace std;
bool load_game( data::player &player , data::board &board , std::map <int , string> &graphical , std::vector <int> &dist , int &num_player , int &nrows , int &snake_count , int &ladder_count)
{
    QString str = QDir::currentPath() ;
    if(!QDir(str + "/sound").exists() ||  !QDir(str + "/save").exists())
    {
        return false;
    }
    if(!QDir(str + "/save/graphic").exists())
    {
       return false;
    }
    if(!QDir(str + "/save/player").exists() || !QDir(str + "/save/board").exists())
    {
        return false;
    }
    std::string self_path = str.toUtf8().constData();
    try {
        char * buff = new char(1);
        ifstream input;
        string playerPath = self_path +  "/save/player/pname" ;
        string boardPath = self_path + "/save/board/bholder";
        string graphicPath = self_path + "/save/graphic/graphical";
        string distPath = self_path + "/save/dist/distination";
        input.open(boardPath.c_str() , ios_base::in);
        if(input.is_open())
        {
            input>>nrows;
            input>>snake_count;
            input>>ladder_count;
            for(int i = 0 ; i< nrows*nrows ; i++)
            {
                input>>board.holder[i];
            }
            input.close();
        }
        else{
            return false;
        }
for(int i = 0 ; i<nrows * nrows ; i++)
{
 dist.push_back(0);
}
        input.open(distPath.c_str() , ios_base::in);
        if(input.is_open())
        {
            for(int i = 0 ; i< nrows*nrows ; i++)
            {
                input>>dist[i];
            }
            input.close();
        }
        else{
            return false;
        }



        input.open(graphicPath.c_str() , ios_base::in);
        if(input.is_open())
        {
        string inp; int index;
            while(input>>inp)
            {
             index = stoi(inp);
             input>>inp;
             graphical[index]=inp;

            }

            input.close();
        }
        else{
            return false;
        }
        input.open(playerPath.c_str() , ios_base::in);
        if(input.is_open())
        {
            input>>num_player;
            for(int i = 0 ; i<num_player ; i++)
            {
                input>>player.name[i];
            }
            input.close();
        }
        else{
            return false;
        }
        playerPath = self_path +  "/save/player/pcell" ;
        input.open(playerPath.c_str() , ios_base::in);
        if(input.is_open())
        {
            for(int i = 0 ; i<num_player ; i++)
            {
                input>>player.cell[i];
            }
            input.close();
        }
        else{
            return false;
        }
        playerPath = self_path +  "/save/player/ppermit" ;
        input.open(playerPath.c_str() , ios_base::in);
        if(input.is_open())
        {
            for(int i = 0 ; i<num_player ; i++)
            {
                input>>player.Play_Permit[i];
            }

            input.close();
        }
        else{
            return false;
        }

      delete buff;

    } catch (const std::exception& e) {
        std::cout << e.what();
    }


    return true;
}
bool save_game( data::player &player , data::board &board, std::map< int , std::string> &graphical , std::vector <int> &dist ,  int &num_player , int &nrows , int &snake_count , int &ladder_count)
{
    QString str = QDir::currentPath() ;
    if(!QDir(str + "/sound").exists())
    {
        QDir().mkdir(str + "/sound");
    }
    if(!QDir(str + "/save").exists())
    {
        QDir().mkdir(str + "/save");
    }
    if(!QDir(str + "/save/player").exists())
    {
        QDir().mkdir(str + "/save/player");
    }
    if(!QDir(str + "/save/graphic").exists())
    {
        QDir().mkdir(str + "/save/graphic");
    }
    if(!QDir(str + "/save/dist").exists())
    {
        QDir().mkdir(str + "/save/dist");
    }
    if(!QDir(str + "/save/board").exists())
    {
        QDir().mkdir(str + "/save/board");
    }
    std::string self_path = str.toUtf8().constData();
    try {
        char * buff = new char(1);
        fstream output;
        string playerPath = self_path +  "/save/player/pname" ;
        string boardPath = self_path + "/save/board/bholder";
        string graphicPath = self_path + "/save/graphic/graphical";
        string distPath = self_path + "/save/dist/distination";
        output.open(boardPath.c_str() , ios_base::out);
        if(output.is_open())
        {
            output<<nrows<<endl;
            output<<snake_count<<endl;
            output<<ladder_count<<endl;
            for(int i = 0 ; i< nrows*nrows ; i++)
            {
                output<<board.holder[i]<<endl;
            }
            output.close();
        }
        else{
            return false;
        }

        output.open(distPath.c_str() , ios_base::out);
        if(output.is_open())
        {
            for(int i = 0 ; i< nrows*nrows ; i++)
            {
                output<<dist[i]<<endl;
            }
            output.close();
        }
        else{
            return false;
        }


        output.open(graphicPath.c_str() , ios_base::out);
        if(output.is_open())
        {
             for(auto iter = graphical.begin(); iter != graphical.end(); ++iter)
            {
             output<<iter->first<<" "<<iter->second<<endl;
            }
            output.close();
        }
        else{
            return false;
        }

 playerPath = self_path +  "/save/player/pname" ;
        output.open(playerPath.c_str() , ios_base::out);
        if(output.is_open())
        {
          output<<num_player<<endl;
            for(int i = 0 ; i<num_player ; i++)
            {
                output<<player.name[i]<<endl;
            }
            output.close();
        }
        else{
            return false;
        }
        playerPath = self_path +  "/save/player/pcell" ;
        output.open(playerPath.c_str() , ios_base::out);
        if(output.is_open())
        {
            for(int i = 0 ; i<num_player ; i++)
            {
                output<<player.cell[i]<<endl;
            }
            output.close();
        }
        else{
            return false;
        }
        playerPath = self_path +  "/save/player/ppermit" ;
        output.open(playerPath.c_str() , ios_base::out);
        if(output.is_open())
        {
            for(int i = 0 ; i<num_player ; i++)
            {
                output<<player.Play_Permit[i]<<endl;
            }

            output.close();
        }
        else{
            return false;
        }


        delete buff;

    } catch (const std::exception& e) {
        std::cout << e.what();
    }
    return true;
}

void nsleep(int n)
{
    struct timespec req ;
    req.tv_sec = 0;
    req.tv_nsec = n * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}

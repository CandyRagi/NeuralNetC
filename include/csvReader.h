#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class csvReader
{
        private: 

                string * dataSet;

        public:
                int row;
                int col;

                csvReader()
                {
                        this->dataSet=nullptr;
                        this->row=0;
                        this->col=0;
                }

                csvReader(string fileName)
                {       this->row=0;
                        this->col=0;
                        ifstream file(fileName);

                        if(!file.is_open())
                        {
                                cout<<"File error. Pls Check the file name and location"<<endl;
                                return;
                        }

                        string line;


                        getline(file,line);
                        line+='\n';
                        for(int i=0;line[i]!='\n';i++)
                        {
                                if(line[i]==',')
                                {
                                        this->col++;
                                }
                        }
                        this->col++;

                        while(getline(file,line))
                        {
                                this->row++;
                        }

                        cout<<"Columns: "<<this->col<<" Rows: " <<this->row<<endl<<endl;

                        this->dataSet=new string[this->row*this->col];

                        file.clear();
                        file.seekg(0,ios::beg); //Restart from top
                        
                        getline(file,line);


                        

                                                


                }

};


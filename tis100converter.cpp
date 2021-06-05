#include <iostream>
#include <fstream>
#include <vector>
#include <vector> 

using namespace std;

std::string stringline;

std::string ReadNthLine(const std::string& filename, int N)
{
   std::ifstream in(filename.c_str());

   stringline.reserve(3);    

   //skip n lines
   for(int i = 0; i < N; ++i)
       std::getline(in, stringline);

   std::getline(in,stringline);
   cout<<stringline;



   return stringline; 
}



int main() {

  
  string tasm = "";
  
  cout<<"What is the TIS300 assembly file you want to convert?";
  cin>>tasm;
  
  ofstream CPPFile(tasm + ".cpp");
  
  CPPFile << "#include <iostream>\n";
  CPPFile << "int main() {\n";
  CPPFile << "int ACC = 0;\n";
  CPPFile << "int BAK = 0;\n";
  CPPFile << "int NIL = 0;\n";

 //reading line by line
  string filename(tasm);
    vector<char> bytes;

    FILE* input_file = fopen(filename.c_str(), "r");

    unsigned char character = 0;
    int opiterator = 0;
    while (!feof(input_file)) {
       character = getc(input_file);
       cout << character << "-";
       opiterator++;

    //opcode check
    if (opiterator == 3) { //3 characters equals an opcode
        cout<<"Reading the first line...\n";
        ReadNthLine(tasm, 1); //reads the 1st line
        cout<<stringline<<"\n";

        //specific opcode check
        if(stringline == "ADD"){
          CPPFile << "ACC = ACC +" <<stringline[4]<< ";" << "\n";
        }
        else if(stringline == "JGZ"){
          CPPFile << "if (ACC > 0){\n";
          CPPFile << "};\n";
        }

    }
    else if (opiterator == 6){
        cout<<"TEST\n";
        ReadNthLine(tasm, 2); //reads the 2nd line
        cout<<stringline<<"\n";

        //specific opcode check
        if(stringline == "ADD"){
          CPPFile << "ACC = ACC +" <<stringline[4]<< ";" << "\n";
        }
        else if(stringline == "JGZ"){
          CPPFile << "if ACC > 0{\n";
          CPPFile << "};\n";
        }
    }
    else if (opiterator == 9) {
        cout<<"TEST\n";
        ReadNthLine(tasm, 3);
        cout<<stringline<<"\n";

        //specific opcode check
        if(stringline == "ADD"){
          CPPFile << "ACC = ACC +" <<stringline[4]<< ";" << "\n";
        }
        else if(stringline == "JGZ"){
          CPPFile << "if ACC > 0{\n";
          CPPFile << "};\n";
        }
    }
  }
  cout << endl;
  fclose(input_file);
  CPPFile << "return 0;\n";
  CPPFile << "}";
  CPPFile.close();
}

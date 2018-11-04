
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int

 int FindFunctionDefn(const char *strFunctionName, const char *strSourceCode)
{
    if (strFunctionName == NULL || strSourceCode == NULL)
    {
        return 0;
    }

    string str_func(strFunctionName);
    string str_source_unformatted(strSourceCode);
    vector<char> formatted;
    vector<char> no_new_line;
    for (int i = 0; i < str_source_unformatted.size(); i++)
    {
        if (i<str_source_unformatted.size()-1 && str_source_unformatted.substr(i, 2) == "\\n")
        {  
            formatted.push_back('\n');
            i += 1;
            continue;
        }

        formatted.push_back(str_source_unformatted[i]);
        no_new_line.push_back(str_source_unformatted[i]);
    }

    string str_source(formatted.begin(), formatted.end());
    string source_without_lines(no_new_line.begin(), no_new_line.end());

    if (str_func.size() > str_source.size())
        return 0;

    int line_count = 1, character_match_count = 0, no_lines_index = 0;
    bool exists = false;
    for (int i = 0; i < str_source.size(); i++, no_lines_index++)
    {
        if (str_source[i] == '\n'){
             no_lines_index--;
             line_count++;
        }
            
        if (str_source[i] == str_func[character_match_count])
            character_match_count++;
        else
            character_match_count = 0;
        if (character_match_count == str_func.size() && no_lines_index > 0 && no_lines_index < source_without_lines.size() - 3)
        {

            if (source_without_lines.substr(no_lines_index + 1, 3) == "(){")
            {
                exists = true;
                break;
            }
        }
    }

    if (exists)
    {
        return line_count;
    }

    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    char strFunctionName[] = "func4";
    char strSourceCode[] = "int func2(){};\\n int func2(){};\\n int func4(){}";
    cout << FindFunctionDefn(strFunctionName, strSourceCode) << endl;
    return 0;
}
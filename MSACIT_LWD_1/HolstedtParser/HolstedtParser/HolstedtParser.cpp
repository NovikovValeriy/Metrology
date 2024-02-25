#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_set>
#include <cmath>
#include <map>

std::vector<std::map<std::string, int>> parse(std::string filePath)
{
    std::string fileContent;
    char readChar;


    std::map<std::string, int> operandDict;
    std::map<std::string, int> operandDict_;
    std::map<std::string, int> operatorDict;
    std::vector<std::map<std::string, int>> dicts;

    std::ifstream phpFile(filePath);
    if (phpFile.is_open())
    {
        while (phpFile.get(readChar))
            fileContent += readChar;
    }
    else
    {
        throw std::runtime_error("Valera, put' k failu huyna, peredelivay!");
    }
    phpFile.close();

    std::regex operandRegex("\\$([_a-zA-Z_][a-zA-Z0-9_]*)");
    std::regex operatorRegex("\\+\\+|--(?!\\=)|\\*\\*|==|!=|<=|>=|&&|\\|\\||\\+=(?!\\=)|-=\\b(?!\\=)|\\*=(?!\\=)|/=(?!\\=)|%(?!\\=)|<<=|>>=|&=|\\|=|\\^=|~|!(?!\\=)|\\+(?!\\+)|-(?!\\-)|\\*(?!\\=)|/(?!\\=)|%(?!\\=)|<<|>>|&(?!\\=)|\\|(?!\\=)|\\^=|=|<|>|\\?|:|===|!==|<>|->|::\\b|and\\b|or\\b|xor\\b|clone\\b|new\\b|instanceof\\b|print\\b|var\\b|if\\b|else\\b|elseif\\b|switch\\b|case\\b|default\\b|break\\b|continue\\b|while\\b|do\\b|for\\b|foreach\\b|declare\\b|return\\b|try\\b|throw\\b|catch\\b|finally\\b|function\\b|const\\b|abstract\\b|interface\\b|extends\\b|implements\\b|public\\b|protected\\b|private\\b|static\\b|final\\b|namespace\\b|use\\b|require\\b|require_once\\b|include\\b|include_once\\b|global\\b|goto\\b"); ("\\+\\+|--(?!\\=)|\\*\\*|==|!=|<=|>=|&&|\\|\\||\\+=(?!\\=)|-=\\b(?!\\=)|\\*=(?!\\=)|/=(?!\\=)|%(?!\\=)|<<=|>>=|&=|\\|=|\\^=|~|!(?!\\=)|\\+(?!\\+)|-(?!\\-)|\\*(?!\\=)|/(?!\\=)|%(?!\\=)|<<|>>|&(?!\\=)|\\|(?!\\=)|\\^=|=|<|>|\\?|:|===|!==|<>|->|::\\b|and\\b|or\\b|xor\\b|clone\\b|new\\b|instanceof\\b|print\\b|var\\b|if\\b|else\\b|elseif\\b|switch\\b|case\\b|default\\b|break\\b|continue\\b|while\\b|do\\b|for\\b|foreach\\b|declare\\b|return\\b|try\\b|throw\\b|catch\\b|finally\\b|function\\b|const\\b|abstract\\b|interface\\b|extends\\b|implements\\b|public\\b|protected\\b|private\\b|static\\b|final\\b|namespace\\b|use\\b|require\\b|require_once\\b|include\\b|include_once\\b|global\\b|goto\\b");

    std::sregex_iterator operandIter(fileContent.begin(), fileContent.end(), operandRegex);
    std::sregex_iterator operandEnd;

    for (; operandIter != operandEnd; ++operandIter) {
        std::string operand = operandIter->str();
        operandDict_[operand]++;
    }

    for (const auto& pair : operandDict_)
        operandDict[pair.first.substr(1)] = pair.second;

    std::sregex_iterator operatorIter(fileContent.begin(), fileContent.end(), operatorRegex);
    std::sregex_iterator operatorEnd;

    for (; operatorIter != operatorEnd; ++operatorIter) {
        std::string op = operatorIter->str();
        operatorDict[op]++;
    }

    dicts.push_back(operandDict);
    dicts.push_back(operatorDict);
    return dicts;
}

std::vector<double> countMetrics(std::vector<std::map<std::string, int>> dicts)
{
    double programDictionary = 0;
    double programLength = 0;
    double programVolume = 0;
    std::vector<double> metrics;

    programDictionary = dicts[0].size() + dicts[1].size();

    for (const auto& dict : dicts)
        for (const auto& val : dict)
            programLength += val.second;

    programVolume = programLength * log2(programDictionary);

    metrics.push_back(programDictionary);
    metrics.push_back(programLength);
    metrics.push_back(programVolume);

    return metrics;
}


int main() {
    std::string filePath = "C:\\Users\\dzmitry\\source\\repos\\4sem\\Metrology\\Lab1\\Metrology\\MSACIT_LWD_1\\example.php";
  
    const auto dicts = parse(filePath);
    const auto metrics = countMetrics(dicts);

    //dicts[0] -- operands  - <str, int>
    //dicts[1] -- operators - <str, int>
    //metrics[0] -- program dictionary - double
    //metrics[1] -- program length - double
    //metrics[2] -- program volume - double



    std::cout << "OPERANDS:\n";
    for (const auto& entry : dicts[0]) 
        std::cout << entry.first << ": " << entry.second << "\n";

    std::cout << "\nOPERATORS:\n";
    for (const auto& entry : dicts[1])
        std::cout << entry.first << ": " << entry.second << "\n";

    std::cout << "\nSLOVAR PROGRAMMY\n" << metrics[0] << '\n';

    std::cout << "\nDLINA PROGRAMMY\n" << metrics[1] << '\n';

    std::cout << "\nOBYOM PROGRAMMY\n" << metrics[2] << '\n';

    return 0;
}
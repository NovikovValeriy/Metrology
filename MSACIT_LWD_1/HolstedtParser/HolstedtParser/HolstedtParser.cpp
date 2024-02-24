#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<string> operators = {
    "++", "--", "**", "==", "!=", "<=", ">=", "&&", "||", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "|=", "^=",
    "~", "!", "+", "-", "*", "/", "%", "<<", ">>", "&", "|", "^", "=", "<", ">", "?", ":", "===", "!==", "<>", "->",
    "::", "and", "or", "xor", "clone", "new", "instanceof", "print", "var", "if", "else", "elseif", "switch", "case",
    "default", "break", "continue", "while", "do", "for", "foreach", "declare", "return", "try", "throw", "catch",
    "finally", "function", "const", "abstract", "interface", "extends", "implements", "public", "protected", "private",
    "static", "final", "namespace", "use", "require", "require_once", "include", "include_once", "global", "goto"
};

string preprocessCode(const string& code) {
    // Удаление комментариев
    string result = regex_replace(code, regex("//.*|/\\*.*?\\*/"), "");

    // Удаление строковых литералов
    result = regex_replace(result, regex("\"(?:\\\\.|[^\\\\\"])*\"|'(?:\\\\.|[^\\\\'])*'"), "");

    // Удаление heredoc и nowdoc синтаксиса
    result = regex_replace(result, regex("<<<['\"]?[A-Za-z_]+['\"]?(?:.|\\n)*?\\n[A-Za-z_]+;"), "");

    return result;
}

std::vector<double> calculateHalsteadMetrics(const string& code) {
    unordered_set<string> uniqueOperators;
    unordered_set<string> uniqueOperands;
    regex tokenRegex("\\b\\w+\\b");
    smatch match;

    // Поиск уникальных операторов и операндов
    auto tokenIteratorBegin = sregex_iterator(code.begin(), code.end(), tokenRegex);
    auto tokenIteratorEnd = sregex_iterator();

    for (sregex_iterator it = tokenIteratorBegin; it != tokenIteratorEnd; ++it) {
        string token = (*it).str();
        if (operators.find(token) != operators.end()) {
            uniqueOperators.insert(token);
        }
        else {
            uniqueOperands.insert(token);
        }
    }

    // Вычисление метрик Холстедта
    double programLength = distance(tokenIteratorBegin, tokenIteratorEnd);
    double vocabularySize = uniqueOperators.size() + uniqueOperands.size();
    double programVolume = programLength * log2(vocabularySize);
    double programDifficulty = (uniqueOperators.size() / 2.0) * (uniqueOperands.size() > 0 ? (programLength * 1.0) / uniqueOperands.size() : 0);
    double programEffort = programVolume * programDifficulty;
    double programTime = programEffort / 18.0;

    std::vector<double> metrics = std::vector<double>();
    metrics.push_back(programLength);
    metrics.push_back(vocabularySize);
    metrics.push_back(programLength);
    metrics.push_back(programVolume);
    metrics.push_back(programDifficulty);
    metrics.push_back(programEffort);
    metrics.push_back(programTime);
    return metrics;
}

int main() {
    // Чтение кода из файла
    std::string filePath = "D:\\Uni\\MSACIT\\MSACIT_LWD_1\\example.php";
   ifstream inputFile(filePath);
    string code((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    // Предварительная обработка кода
    string preprocessedCode = preprocessCode(code);

    // Вычисление метрик Холстедта
    std::vector<double> metrics = calculateHalsteadMetrics(preprocessedCode);

    // Вывод результатов
    for (double metric : metrics)
    {
        std::cout << metric <<'\n';
    }

    return 0;
}
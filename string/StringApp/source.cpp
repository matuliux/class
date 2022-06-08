#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <locale>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <regex>

int main() {
    std::ifstream in("name.txt");      // io streams
    std::ofstream out("result.txt");
    std::map<std::string, std::vector<int>> uniq_words;  // a set to store unique words

        // ctyp facet of default locale to identify punctuations
    std::locale loc;
    const std::ctype<char>& ctyp = std::use_facet<std::ctype<char> >(loc);

    std::string word, eilute;
    int line = 0;

    for (int i = 0; std::getline(in, eilute); i++) {
        line++;
    }

    in.close();
    std::ifstream inn("name.txt");

    for (int i = 1; i <= line; i++) {
        std::getline(inn, eilute);
        std::stringstream x;
        x << eilute;
        while (x >> word) {          // split text in words
            // ignore any punctuation at the beginning or the end of the word
            auto beg = word.begin();
            while ((beg != word.end()) && ctyp.is(ctyp.punct, *beg)) {
                beg++;
            }
            auto end = word.end();
            while ((end > beg) && ctyp.is(std::ctype<char>::punct, end[-1])) end--;

            for (auto it = beg; it != end; it++) {     // convert what is kept to lower case
                *it = ctyp.tolower(*it);
            }
            uniq_words[(std::string(beg, end))].push_back(i);   // insert the lower case word in the set
        }
    }
    // Ok, we have all unique words: write them to output file
    out << std::setw(15) << std::left << "Zodis" << "|" << " Kiek kartu pasikartojo" << std::endl;
    for (int i = 0; i < 51; i++) out << "-";
    out << std::endl;
    for (auto w : uniq_words) {
        if (w.second.size() > 1) {
            out << std::setw(15) << std::left << w.first << "| " << w.second.size() << std::endl;
        }
    }

    out << std::endl << std::endl << std::setw(15) << std::left << "Zodis" << "|" << " Eilutes, kuriose pasikartoja zodis" << std::endl;
    for (int i = 0; i < 51; i++) out << "-";
    out << std::endl;

    for (auto w : uniq_words) {
        if (w.second.size() > 1) {
            out << std::setw(15) << std::left << w.first << "| ";
            for (int x : w.second) {
                out << x << " ";
            }
            out << std::endl;
        }
    }
    out << std::endl; inn.close();



    std::ifstream input("name.txt");
    std::stringstream buffer; std::string w;
    buffer << input.rdbuf();

    std::regex word_regex(
        R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)",
        std::regex::extended
    );

    out << "Rastos URL nuorodos " << std::endl;

    while (buffer >> w) {

        if (std::regex_match(w, std::regex("https?:\\/\\/(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)"))) out << w << std::endl;
        if (std::regex_match(w, std::regex("[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)"))) out << w << std::endl;
    }

    return 0;
}


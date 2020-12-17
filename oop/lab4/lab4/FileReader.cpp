#include "FileReader.h"

std::vector<Elections> FileReader::read() {
    std::vector <Elections> elections;
    std::ifstream in("in.txt");
    std::string line;
    if (!in.is_open()){
        in.close();
        throw std::exception("Can not open the file!");
    } else {
        std::string name1;
        std::string name2;
        std::string name3;
        std::string date;
        std::string work;
        std::string rating;
        while(getline(in, line)){
            int nameEnd1 = line.find(' ',0);
            name1 = line.substr(0,nameEnd1);

            int nameEnd2 = line.find(' ',nameEnd1+1);
            name2 = line.substr(nameEnd1+1,nameEnd2-nameEnd1-1);

            int nameEnd = line.find(' ',nameEnd2+1);
            name3 = line.substr(nameEnd2+1,nameEnd-nameEnd2-1);

            int dateEnd = line.find(" \"",nameEnd+1);
            date = line.substr(nameEnd+1, dateEnd-nameEnd-1);

            int workEnd = line.find("\" ",dateEnd+1);
            work = line.substr(dateEnd+2, workEnd-dateEnd-2);

            int ratingEnd = line.length()-1;
            rating = line.substr(workEnd+2, ratingEnd-workEnd-1);

            elections.push_back(Elections(name1.append(" ").append(name2).append(" ").append(name3), date, work, rating));
        }
        in.close();
        return std::move(elections);
    }
}

#include "../../utils/stringify.hpp"

namespace utils
{
    namespace stringify
    {
        const std::string &StringifyFormattedDate(time_t time)
        {
            char *date = ctime(&time);
            const std::string &standardStringDate = date;
            return standardStringDate;
        };
    }
}

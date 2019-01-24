#include "Grok.h"
#include <algorithm>
#include <locale>

namespace
{
    std::string Uppercase(const std::string_view &str)
    {
        std::string res(str);
        std::transform(cbegin(res), cend(res), begin(res), [loc = std::locale("RU")](const auto &i)
        {
            return std::toupper(i, loc);
        });
        return res;
    }
}

bool Grok::IsPositiveAnswer(const std::string_view &answer)
{
    const static auto positiveAnswers = { "дю", "1", "YES", "унвс", "янцкюяем", "осярэ" };
    return std::find(cbegin(positiveAnswers), cend(positiveAnswers), Uppercase(answer)) != cend(positiveAnswers);
}

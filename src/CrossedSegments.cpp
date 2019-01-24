#include "SmartStream/SmartStream.h"
#include "Geometry/RandomSegments.h"
#include "Grok/Grok.h"
#include <algorithm>

namespace Logic
{
    bool IsIntersect(const Geometry::Segment &a, const Geometry::Segment &b)
    {
        const long double x1 = a.A.x, y1 = a.A.y, x2 = a.B.x, y2 = a.B.y; // первый отрезок
        const long double x3 = b.A.x, y3 = b.A.y, x4 = b.B.x, y4 = b.B.y; // второй отрезок

        const long double A1 = y2 - y1;
        const long double B1 = x1 - x2;
        const long double C1 = -A1 * x1 - B1 * y1;

        const long double A2 = y4 - y3;
        const long double B2 = x3 - x4;
        const long double C2 = -A2 * x3 - B2 * y3;

        const long double f1 = A1 * x3 + B1 * y3 + C1;
        const long double f2 = A1 * x4 + B1 * y4 + C1;
        const long double f3 = A2 * x1 + B2 * y1 + C2;
        const long double f4 = A2 * x2 + B2 * y2 + C2;
        // с учетом касания
        return (f1 * f2 <= 0 && f3 * f4 <= 0);
    }
}

namespace UI
{
    using namespace SmartStream;

    std::vector<Geometry::Segment> GenerateSegments()
    {
        size_t len;
        Geometry::Coordinate xymin, xymax;
        io << "Процедура генерации случайных отрезков:" << tabl
            << "Количество отрезков: " >> len
            << "Минимальное значение для координат x и y отрезка: " >> xymin
            << "Максимальное значение для координат x и y отрезка: " >> xymax;
        auto segments = Geometry::RandomSegments(len, xymin, xymax);
        std::string userAnswer;
        io << segments << "Вы хотите добавить вручную несколько отрезков (да или нет): " >> userAnswer;
        if (Grok::IsPositiveAnswer(userAnswer))
        {
            io << "Количество вручную вводимых отрезков: " >> len;
            std::generate_n(std::back_inserter(segments), len, Input<Geometry::Segment>);
        }
        io << untab;
        return segments;
    }

    std::vector<Geometry::Segment> ReadSegments()
    {
        io << "Процедура ввода отрезков:" << tabl;
        size_t len;
        io << "Количество отрезков: " >> len;
        std::vector<Geometry::Segment> segments;
        std::generate_n(std::back_inserter(segments), len, Input<Geometry::Segment>);
        io << segments << untab;
        return segments;
    }

    std::vector<Geometry::Segment> AnywayGetSegments()
    {
        std::string userAnswer;
        io << "Вы хотите сгенерировать отрезки автоматически (да или нет): " >> userAnswer;
        return Grok::IsPositiveAnswer(userAnswer) ? GenerateSegments() : ReadSegments();
    }

    void ShowAllIntersections(const std::vector<Geometry::Segment> &segments)
    {
        io << "Процедура поиска пересекающихся отрезков. . ." << tabl;
        bool wasResult = false;
        for (auto a = cbegin(segments); a < cend(segments); ++a)
        {
            for (auto b = a + 1; b < cend(segments); ++b)
            {
                if (Logic::IsIntersect(*a, *b))
                {
                    wasResult = true;
                    io << "Отрезки " << *a << " и " << *b << " пересекаются!" << endl;
                }
            }
        }
        io << (wasResult ? "Поиск завершен." : "Пересечения не обнаружены.") << untabl;
    }
}

int main()
{
    while (true)
    {
        UI::ShowAllIntersections(UI::AnywayGetSegments());
        SmartStream::io << SmartStream::wait << SmartStream::wait;
    }
}
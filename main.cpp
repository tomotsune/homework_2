#include <iostream>
#include "Set.h"

using namespace std;

/**
 * 存储结构: 动态线性表.
 * Created by 胡海彬(tomo) on 2020/9/21.
 */
int main() {
    Set<int> s1, s2;
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s2.add(3);
    s2.add(4);
    s2.add(5);
    auto product{s1 * s2};
    auto sum{s1 + s2};
    auto difference{s1 - s2};
    cout << "----START----" << endl;
    cout << "s1: " << s1 << " length: " << s1.getLength() << endl;
    cout << "s2: " << s2 << " length: " << s1.getLength() << endl;
    cout << "--------" << endl;

    cout << "--SHOW SET OPERATIONS--" << endl;
    cout << "s1 + s2: " << sum << endl;
    cout << "s1 * s2: " << product << endl;
    cout << "s1 - s2: " << difference << endl;
    cout << "--------" << endl;

    cout << "--SET COMPARISON--" << endl;
    s1.removeByData(3);
    cout << "s1: " << s1 << endl;
    cout << "difference: " << difference << endl;
    cout << "sum: " << sum << endl;
    if (s1 <= sum)cout << "s1 <= sum" << endl;
    if (s1 == difference)cout << "s1==difference" << endl;

    cout << "---CLEAN UP---" << endl;
    cout << "before: " << s1 << endl;
    s1.clear();
    cout << "after: " << s1 << endl;
    if (s1.isEmpty())cout << "s1 has cleared" << endl;
    cout << "----END----" << endl;

    return 0;
}

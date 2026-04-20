//4264838   Aug 11, 2013 12:28:28 PM	fuwutu	 17A - Noldbach problem	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int prime[1000] = {3, 5}, count(2);
    for (int number = 7; number <= n && k != 0; number += 2)
    {
        int i = 0;
        while (i < count && number % prime[i] != 0)
        {
            ++i;
        }
        if (i == count)
        {
            for (int j = 1; j < count; ++j)
            {
                if (prime[j] + prime[j-1] + 1 == number)
                {
                    k -= 1;
                    break;
                }
            }
            prime[count++] = number;
        }
    }
    printf(k == 0 ? "YES\n" : "NO\n");
    return 0;
}
// 102B
#include <cstdio>
int main() {
    char digits[100001];
    scanf("%s", digits);

    int times(0);
    if (digits[1] != 0)
    {
        int digitsum(0);
        char* p = digits;
        while (*p != 0)
        {
            digitsum += (*p - '0');
            ++p;
        }
        ++times;

        while (digitsum > 9)
        {
            int m(digitsum);
            digitsum = 0;
            while (m != 0)
            {
                digitsum += m % 10;
                m /= 10;
            }
            ++times;
        }
    }
    printf("%d\n", times);
    return 0;
}
// 104A
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 10 || n > 21)
    {
        cout << 0 << endl;
    }
    else if (n == 20)
    {
        cout << 15 << endl;
    }
    else
    {
        cout << 4 << endl;
    }
    return 0;
}
// 106A
#include <cstdio>
using namespace std;

int rank(char c)
{
    const char* order = "6789TJQKA";
    char* find = const_cast<char*>(order);
    while (*find != c)
    {
        ++find;
    }
    return find - order;
}

int main()
{
    char suit[2], card1[3], card2[3];
    scanf("%s%s%s", suit, card1, card2);

    bool beat = (card1[1] == suit[0] && card2[1] != suit[0])
        || (card1[1] == card2[1] && rank(card1[0]) > rank(card2[0]));
    printf(beat ? "YES\n" : "NO\n");
    return 0;
}
// 106B
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, speed[101], ram[101], hdd[101], cost[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &speed[i], &ram[i], &hdd[i], &cost[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (speed[i] < speed[j] && ram[i] < ram[j] && hdd[i] < hdd[j])
            {
                cost[i] = 1001; // 100 <= cost <= 1000
            }
        }
    }

    printf("%u\n", min_element(cost + 1, cost + 1 + n) - cost);

    return 0;
}
// 108A
#include <cstdio>

int main()
{
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    do 
    {
        ++mm;
        if (mm == 60)
        {
            ++hh;
            mm = 0;
        }
        if (hh == 24)
        {
            hh = 0;
        }
    } while (hh % 10 * 10 + hh / 10 != mm);
    printf("%02d:%02d\n", hh, mm);
    return 0;
}
// 110A
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    int count = 0;
    while (n != 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
        {
            count += 1;
        }
        n /= 10;
    }
    if (count == 4 || count == 7)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// 110B
n = int(input())
s = "abcd" * (n // 4) + "abcd"[0 : n % 4]
print(s)
// 112A
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << strcmp(s1.c_str(), s2.c_str()) << endl;
    return 0;
}
// 114A
#include <iostream>

using namespace std;

int main()
{
    int k, l, importance(-1);
    cin >> k >> l;
    while (l % k == 0)
    {
        l /= k;
        importance += 1;
    }
    if (importance >= 0 && l == 1)
    {
        cout << "YES" << endl << importance << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// 116A
#include <cstdio>

int main()
{
    int n, a, b, c(0), m(0);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        c -= a;
        c += b;
        if (c > m)
        {
            m = c;
        }
    }

    printf("%d\n", m);
    return 0;
}
//4057937   Jul 13, 2013 9:13:14 AM	fuwutu	 116B - Little Pigs and Wolves	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <cstdio>
// 116B
int main()
{
    int n, m;
    char c[12][13];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", &c[i][1]);
    }
    int eaten(0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (c[i][j] == 'W')
            {
                if (c[i-1][j] == 'P' || c[i+1][j] == 'P' || c[i][j-1] == 'P' || c[i][j+1] == 'P')
                {
                    eaten += 1;
                }
            }
        }
    }
    printf("%d\n", eaten);
    return 0;
}
//4005085     Jul 3, 2013 3:50:19 AM	fuwutu	 118A - String Task	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
// 118A
using namespace std;

int main()
{
    string s, r;
    cin >> s;
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c += 'a' - 'A';
        }
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y')
        {
            r.append(1, '.');
            r.append(1, c);
        }
    }
    cout << r << endl;
    return 0;
}
//4027858   Jul 5, 2013 8:37:21 PM	fuwutu	 118B - Present from Lena	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <cmath>
// 118B
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = -n; row <= n; ++row)
    {
        int top = n - abs(row);
        for (int i = 0; i < abs(row); ++i)
        {
            cout << "  ";
        }
        for (int i = 0; i < top; ++i)
        {
            cout << i << " ";
        }
        for (int i = top; i > 0; --i)
        {
            cout << i << " ";
        }
        cout << 0 << endl;
    }
    return 0;
}
// 119A
//4006915   Jul 3, 2013 6:07:36 PM	fuwutu	 119A - Epic Game	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int GCD(int m, int n)
{
    int r;
    while ((r = m % n) != 0)
    {
        m = n;
        n = r;
    }
    return n;
}

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    while (true)
    {
        n -= GCD(a, n);
        if (n == 0)
        {
            cout << 0 << endl;
            break;
        }
        n -= GCD(b, n);
        if (n == 0)
        {
            cout << 1 << endl;
            break;
        }
    }
    return 0;
}
// 122A
//4027427   Jul 5, 2013 6:40:47 PM	fuwutu	 122A - Lucky Division	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

bool lucky(int n)
{
    while (n != 0)
    {
        if (n % 10 != 4 && n % 10 != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool almost_lucky(int n)
{
    if (lucky(n))
    {
        return true;
    }

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0 && (lucky(i) || lucky(n / i)))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    if (almost_lucky(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
// 122B
#4076744   Jul 15, 2013 8:50:51 PM	fuwutu	 122B - Lucky Substring	 Python 3	Accepted	62 ms	100 KB
s = input()
count4 = count7 = 0
for c in s:
    if c == '4':
        count4 += 1
    elif c == '7':
        count7 += 1
if count4 == 0 and count7 == 0:
    print(-1)
elif count4 >= count7:
    print(4)
else:
    print(7)
// 124A
//4032912   Jul 7, 2013 5:46:56 AM	fuwutu	 124A - The number of positions	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(n - a, b + 1) << endl;
    return 0;
}
// 127A
//4034181   Jul 7, 2013 2:00:39 PM	fuwutu	 127A - Wasted Time	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    double x, y, x0, y0, total(0.0);
    cin >> x0 >> y0;
    while (--n)
    {
        cin >> x >> y;
        total += sqrt((x - x0) * (x - x0) + (y - y0) * (y - y0));
        x0 = x;
        y0 = y;
    }
    cout << fixed << setprecision(6) << total * k / 50 << endl;
    return 0;
}
// 127B
//4035363   Jul 7, 2013 7:45:38 PM	fuwutu	 127B - Canvas Frames	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, count[101] = {0};
    cin >> n;
    while (n--)
    {
        cin >> a;
        count[a] += 1;
    }
    int total = 0;
    for (int i = 1; i <= 100; ++i)
    {
        total += count[i] / 2;
    }
    cout << total / 2 << endl;
    return 0;
}
// 129A
//4033714   Jul 7, 2013 12:04:07 PM	fuwutu	 129A - Cookies	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, odd(0), even(0);
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            even += 1;
        }
        else
        {
            odd += 1;
        }
    }

    cout << (odd % 2 == 1 ? odd : even) << endl;
    return 0;
}
// 131A
//4006936   Jul 3, 2013 6:14:19 PM	fuwutu	 131A - cAPS lOCK	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool change = true;
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] >= 'a')
        {
            change = false;
            break;
        }
    }

    if (change)
    {
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (s[i] >= 'a')
            {
                s[i] -= ('a' - 'A');
            }
            else
            {
                s[i] += ('a' - 'A');
            }
        }
    }

    cout << s << endl;
    return 0;
}
// 131B
//4034968   Jul 7, 2013 5:38:17 PM	fuwutu	 131B - Opposites Attract	 GNU C++0x	Accepted	31 ms	0 KB
#include <cstdio>

using namespace std;

int main()
{
    int n, t, count[21] = {0};
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        count[t + 10] += 1;
    }
    long long result = static_cast<long long>(count[10]) * static_cast<long long>(count[10] - 1) /2;
    for (int i = 0; i < 10; ++i)
    {
        result += static_cast<long long>(count[i]) * static_cast<long long>(count[20 - i]);
    }
    printf("%I64d\n", result);
    return 0;
}
// 131C
//4212008	 Aug 1, 2013 9:09:20 AM	fuwutu	 131C - The World is a Theatre	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <iostream>

using namespace std;

long long C(int n, int m)
{
    long long result(1);
    for (int i = 0; i < m; ++i)
    {
        result *= (n - i);
        result /= (i + 1);
    }
    return result;
}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    long long ways(0);
    for (int i = 4; i <= t - 1; ++i)
    {
        ways += C(n, i) * C(m, t - i);
    }
    cout << ways << endl;
}
// 133A
//4007157   Jul 3, 2013 7:19:37 PM	fuwutu	 133A - HQ9+	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.find_first_of("HQ9") != string::npos)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// 133B
//4136816   Jul 22, 2013 9:05:14 PM	fuwutu	 133B - Unary	 GNU C++0x	Accepted	15 ms	0 KB
#include <cstdio>

int main()
{
    char p[101];
    scanf("%s", p);
    int size(0);
    for (size_t i = 0; p[i] != 0; ++i)
    {
        size *= 16;
        switch (p[i])
        {
        case '>':
            size += 8;
            break;

        case '<':
            size += 9;
            break;

        case '+':
            size += 10;
            break;

        case '-':
            size += 11;
            break;

        case '.':
            size += 12;
            break;

        case ',':
            size += 13;
            break;

        case '[':
            size += 14;
            break;

        case ']':
            size += 15;
            break;

        default:
            break;
        }

        size %= 1000003;
    }
    printf("%d\n", size);
    return 0;
}
// 136A
//4021420   Jul 4, 2013 7:30:15 PM	fuwutu	 136A - Presents	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, p;
    cin >> n;
    vector<int> f(n+1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p;
        f[p] = i;
    }
    cout << f[1];
    for (int i = 2; i <= n; ++i)
    {
        cout << " " << f[i];
    }
    cout << endl;
    return 0;
}
// 136B
//4172198   Jul 27, 2013 5:09:00 AM	fuwutu	 136B - Ternary Logic	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int a, c, ad[20] = {0}, an(0), cd[20] = {0}, cn(0);
    cin >> a >> c;

    while (a != 0)
    {
        ad[an++] = a % 3;
        a /= 3;
    }

    while (c != 0)
    {
        cd[cn++] = c % 3;
        c /= 3;
    }

    int tor(0);
    for (int i = max(an, cn) - 1; i >= 0; --i)
    {
        tor = tor * 3 + (cd[i] + 3 - ad[i]) % 3;
    }
    cout << tor << endl;
    return 0;
}
// 137A
//4035232   Jul 7, 2013 7:00:58 PM	fuwutu	 137A - Postcards and photos	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int result(0), count(1);
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i-1])
        {
            count += 1;
        }
        else
        {
            result += (count + 4) / 5;
            count = 1;
        }
    }
    result += (count + 4) / 5;
    cout << result << endl;
    return 0;
}
// 137B
//4055758   Jul 12, 2013 8:25:21 PM	fuwutu	 137B - Permutation	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, appear[5001] = {0};
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a <= n)
        {
            appear[a] = 1;
        }
    }
    cout << count(appear + 1, appear + n + 1, 0) << endl;
    return 0;
}
// 139A
//4034061   Jul 7, 2013 1:27:10 PM	fuwutu	 139A - Petr and Book	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, y[8] = {0};
    cin >> n;
    for (int d = 1; d <= 7; ++d)
    {
        cin >> y[d];
        y[d] += y[d-1];
    }
    n = (n - 1) % y[7] + 1;
    for (int d = 1; d <= 7; ++d)
    {
        if (y[d] >= n)
        {
            cout << d << endl;
            break;
        }
    }
    return 0;
}
// 140A
//4236895   Aug 6, 2013 4:35:30 PM	fuwutu	 140A - New Year Table	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>
#include <cmath>

int main()
{
    int n;
    double R, r;
    scanf("%d%lf%lf", &n, &R, &r);
    if (   n == 1 && r <= R
        || n == 2 && r * 2 <= R
        || asin(r / (R - r)) * n <= 3.1415927)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
// 141A
//4027532   Jul 5, 2013 7:07:08 PM	fuwutu	 141A - Amusing Joke	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int dict[128] = {0};
    string s;
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i)
    {
        dict[s[i]] += 1;
    }
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i)
    {
        dict[s[i]] += 1;
    }
    cin >> s;
    for (size_t i = 0; i < s.length(); ++i)
    {
        dict[s[i]] -= 1;
    }

    if (count(dict, dict + sizeof(dict) / sizeof(dict[0]), 0) == sizeof(dict) / sizeof(*dict))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
// 143A
//4236777   Aug 6, 2013 3:58:53 PM	fuwutu	 143A - Help Vasilisa the Wise 2	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int a11 = (r1 + c1 - d2) / 2;
    int a12 = r1 - a11;
    int a21 = c1 - a11;
    int a22 = d1 - a11;
    if (a11 != a12 && a11 != a21 && a11 != a22 && a12 != a21 && a12 != a22 && a21 != a22
        && a11 >= 1 && a11 <= 9
        && a12 >= 1 && a12 <= 9
        && a21 >= 1 && a21 <= 9
        && a22 >= 1 && a22 <= 9
        && a21 + a22 == r2
        && a12 + a22 == c2
        && a12 + a21 == d2)
    {
        cout << a11 << " " << a12 << endl;
        cout << a21 << " " << a22 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
// 144A
//4008690   Jul 4, 2013 3:55:22 AM	fuwutu	 144A - Arrival of the General	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;
    int mina(a), maxa(a), mini(0), maxi(0);
    for (int i = 1; i < n; ++i)
    {
        cin >> a;
        if (a > maxa)
        {
            maxa = a;
            maxi = i;
        }
        if (a <= mina)
        {
            mina = a;
            mini = i;
        }
    }
    cout << maxi + (n - 1 - mini) - (mini < maxi ? 1 : 0) << endl;
    return 0;
}
// 146A
//4033946   Jul 7, 2013 12:54:50 PM	fuwutu	 146A - Lucky Ticket	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    size_t n;
    string s;
    cin >> n >> s;

    bool lucky = true;
    int diff(0);
    n /= 2;
    for (size_t i = 0; i < n; ++i)
    {
        if ((s[i] != '4' && s[i] != '7') || (s[n+i] != '4' && s[n+i] !='7'))
        {
            lucky = false;
            break;
        }
        diff += (s[i] - s[n+i]);
    }
    lucky = lucky && (diff == 0);
    cout << (lucky ? "YES" : "NO") << endl;
    return 0;
}
// 148A
//4007107   Jul 3, 2013 7:04:01 PM	fuwutu	 148A - Insomnia cure	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int LCM(int m, int n)
{
    int mm(m), nn(n), r;
    while ((r = m % n) != 0)
    {
        m = n;
        n = r;
    }
    return mm / n * nn;
}

int main()
{
    int k, l, m, n, d, count(0);
    cin >> k >> l >> m >> n >> d;

    int lcm = LCM(LCM(k, l), LCM(m, n));
    if (d > lcm)
    {
        int r = 0;
        for (int i = 1; i <= d % lcm; ++i)
        {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            {
                r += 1;
            }
        }

        int c = r;
        for (int i = d % lcm + 1; i <= lcm; ++i)
        {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            {
                c += 1;
            }
        }

        count = c * (d / lcm) + r;
    }
    else
    {
        for (int i = 1; i <= d; ++i)
        {
            if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            {
                count += 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}
// 149A
//4032903   Jul 7, 2013 5:41:16 AM	fuwutu	 149A - Business trip	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k, a[12], total(0);
    cin >> k;
    for (size_t i = 0; i < 12; ++i)
    {
        cin >> a[i];
        total += a[i];
    }

    if (total < k)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(a, a + sizeof(a) / sizeof(a[0]), greater<int>());
        int sum = 0;
        int month = 0;
        while (sum < k)
        {
            sum += a[month];
            month += 1;
        }
        cout << month << endl;
    }

    return 0;
}
// 151A
//4033228   Jul 7, 2013 9:03:08 AM	fuwutu	 151A - Soft Drinking	 GNU C++0x	Accepted	0 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min(min(k * l / nl, c * d), p / np) / n << endl;
    return 0;
}
// 152A
//4034103   Jul 7, 2013 1:39:50 PM	fuwutu	 152A - Marks	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    size_t n, m;
    cin >> n >> m;
    vector<string> marks(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> marks[i];
    }
    vector<bool> successful(n, false);
    for (size_t subject = 0; subject < m; ++subject)
    {
        char best = '0';
        for (size_t i = 0; i < n; ++i)
        {
            if (marks[i][subject] > best)
            {
                best = marks[i][subject];
            }
        }
        for (size_t i = 0; i < n; ++i)
        {
            if (marks[i][subject] == best)
            {
                successful[i] = true;
            }
        }
    }
    cout << count(successful.begin(), successful.end(), true);
    return 0;
}
// 155A
//4027892   Jul 5, 2013 8:45:43 PM	fuwutu	 155A - I_love_%username%	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, points;
    cin >> n >> points;
    int min(points), max(points), amazing(0);
    while (--n)
    {
        cin >> points;
        if (points < min)
        {
            min = points;
            ++amazing;
        }
        if (points > max)
        {
            max = points;
            ++amazing;
        }
    }
    cout << amazing << endl;
    return 0;
}
// 155B
//4136855   Jul 22, 2013 9:19:15 PM	fuwutu	 155B - Combination	 GNU C++0x	Accepted	15 ms	0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

struct card
{
    int a;
    int b;
};

bool cmp(const card& left, const card& right)
{
    return (left.b > right.b)
        || (left.b == right.b && left.a > right.a);
}

int main()
{
    int n;
    scanf("%d", &n);

    card c[1000];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &c[i].a, &c[i].b);
    }

    sort(c, c + n, cmp);
    int points(c[0].a), cards(c[0].b);
    for (int i = 1; i < n && i <= cards; ++i)
    {
        points += c[i].a;
        cards += c[i].b;
    }

    printf("%d\n", points);
    return 0;
}
// 157A
//4042683   Jul 9, 2013 5:48:49 PM	fuwutu	 157A - Game Outcome	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, m[30][30], r[30] = {0}, c[30] = {0}, win(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m[i][j];
            r[i] += m[i][j];
        }
    }
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            c[j] += m[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (r[i] < c[j])
            {
                win += 1;
            }
        }
    }
    cout << win << endl;
    return 0;
}
// 157B
//4058096   Jul 13, 2013 9:59:34 AM	fuwutu	 157B - Trace	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    int rr(0);
    for (int i = 0; i < n; ++i)
    {
        rr += a[i] * a[i] * (1 - i % 2 * 2);
    }
    double pi = asin(1) * 2;
    cout << fixed << setprecision(10) << (pi * rr) << endl;
    return 0;
}
// 158A
//4004018   Jul 2, 2013 8:42:28 PM	fuwutu	 158A - Next Round	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a;
    for (int i = 0; i < k; ++i)
    {
        cin >> a;
        if (a == 0)
        {
            cout << i << endl;
            return 0;
        }
    }

    int b;
    for (int i = k; i < n; ++i)
    {
        cin >> b;
        if (b != a)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;
    return 0;
}
// 158B
//4005097     Jul 3, 2013 3:58:36 AM	fuwutu	 158B - Taxi	 GNU C++0x	Accepted	46 ms	0 KB
#include <stdio.h>

using namespace std;

int main()
{
    int n, s, count[5]= {0};
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &s);
        count[s] += 1;
    }
    int total = count[4] + count[3] + count[2] / 2;
    count[1] -= count[3];
    if (count[2] % 2 == 1)
    {
        total += 1;
        count[1] -= 2;
    }
    if (count[1] > 0)
    {
        total += (count[1] + 3) / 4;
    }
    printf("%d\n", total);
    return 0;
}
// 158C
//4027816   Jul 5, 2013 8:24:34 PM	fuwutu	 158C - Cd and pwd commands	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string command, parameter;
    vector<string> path;
    cin >> n;
    while (n--)
    {
        cin >> command;
        if (command.compare("pwd") == 0)
        {
            cout << "/";
            for (size_t i = 0; i < path.size(); ++i)
            {
                cout << path[i] << "/";
            }
            cout << endl;
        }
        else
        {
            cin >> parameter;
            size_t pos = 0;
            if (parameter[0] == '/')
            {
                path.clear();
                pos = 1;
            }
            while (true)
            {
                size_t next_pos = parameter.find('/', pos);
                if (next_pos != string::npos)
                {
                    string dir = parameter.substr(pos, next_pos - pos);
                    if (dir.compare("..") != 0)
                    {
                        path.push_back(dir);
                    }
                    else
                    {
                        if (!path.empty())
                        {
                            path.pop_back();
                        }
                    }
                    pos = next_pos + 1;
                }
                else
                {
                    string dir = parameter.substr(pos, string::npos);
                    if (dir.compare("..") != 0)
                    {
                        path.push_back(dir);
                    }
                    else
                    {
                        if (!path.empty())
                        {
                            path.pop_back();
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
// 158D
//4030436   Jul 6, 2013 2:16:09 PM	fuwutu	 158D - Ice Sculptures	 GNU C++0x	Accepted	15 ms	100 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, t[20000], sum(0), partsum[20000];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t[i]);
        sum += t[i];
    }

    int maximum(sum);
    for (int d = 2; d <= n / 3; ++d)
    {
        if (n % d == 0)
        {
            fill(partsum, partsum + d, 0);
            int x = n / d;
            int k = 0;
            for (int i = 0; i < x; ++i)
            {
                for (int j = 0; j < d; ++j)
                {
                    partsum[j] += t[k++];
                }
            }
            for (int j = 0; j < d; ++j)
            {
                if (partsum[j] > maximum)
                {
                    maximum = partsum[j];
                }
            }
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 159B
//4192310   Jul 28, 2013 5:58:29 AM	fuwutu	 159B - Matchmaker	 GNU C++0x	Accepted	342 ms	1500 KB
#include <cstdio>
#include <algorithm>

using namespace std;

struct marker
{
    int ax;
    int by;
};

bool cmp(const marker& left, const marker& right)
{
    return (left.by < right.by)
        || (left.by == right.by && left.ax < right.ax);
}

int main()
{
    marker markers[100000], caps[100000];
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &markers[i].ax, &markers[i].by);
    }

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &caps[i].ax, &caps[i].by);
    }

    sort(markers, markers + n, cmp);
    sort(caps, caps + m, cmp);

    int u(0);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (markers[i].by < caps[j].by)
        {
            ++i;
        }
        else if (markers[i].by > caps[j].by)
        {
            ++j;
        }
        else
        {
            ++u;
            ++i;
            ++j;
        }
    }

    int v(0);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (markers[i].by < caps[j].by)
        {
            ++i;
        }
        else if (markers[i].by > caps[j].by)
        {
            ++j;
        }
        else
        {
            if (markers[i].ax < caps[j].ax)
            {
                ++i;
            }
            else if (markers[i].ax > caps[j].ax)
            {
                ++j;
            }
            else
            {
                ++v;
                ++i;
                ++j;
            }
        }
    }

    printf("%d %d\n", u, v);
    return 0;
}
// 160A
//4007272   Jul 3, 2013 7:54:19 PM	fuwutu	 160A - Twins	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int value = accumulate(a.begin(), a.end(), 0) / 2;

    sort(a.begin(), a.end(), greater<int>());
    int mine = 0;
    size_t i = 0;
    while (mine <= value)
    {
        mine += a[i++];
    }

    cout << i << endl;
    return 0;
}
// 160B
//4033517   Jul 7, 2013 11:10:00 AM	fuwutu	 160B - Unlucky Ticket	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    size_t n;
    string s, l, r;
    cin >> n >> s;
    l = s.substr(0, n);
    r = s.substr(n, n);
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    bool strictly_less(true), strictly_more(true);
    for (size_t i = 0; i < n; ++i)
    {
        if (l[i] >= r[i])
        {
            strictly_less = false;
            break;
        }
    }
    for (size_t i = 0; i < n; ++i)
    {
        if (l[i] <= r[i])
        {
            strictly_more = false;
            break;
        }
    }
    cout << ((strictly_less || strictly_more) ? "YES" : "NO") << endl;
    return 0;
}
// 161A
//4172027   Jul 27, 2013 4:39:57 AM 	fuwutu 	161A - Dress'em in Vests! 	GNU C++0x 	Accepted 	342 ms 	800 KB
#include <cstdio>

using namespace std;

int main()
{
    int n, m, x, y, a[100000], b[100000];
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < m; ++j)
    {
        scanf("%d", &b[j]);
    }

    int count(0);
    for (int i = 0, j = 0; i < n && j < m; )
    {
        if (b[j] < a[i] - x)
        {
            ++j;
        }
        else if (b[j] > a[i] + y)
        {
            ++i;
        }
        else
        {
            a[count] = ++i;
            b[count] = ++j;
            ++count;
        }
    }

    printf("%d\n", count);
    for (int k = 0; k < count; ++k)
    {
        printf("%d %d\n", a[k], b[k]);
    }
    return 0;
}
// 165A
//4033090   Jul 7, 2013 7:51:42 AM	fuwutu	 165A - Supercentral Point	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, x[200], y[200], supercentral(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int bit = 15;
        for (int j = 0; j < n && bit != 0; ++j)
        {
            if (x[j] == x[i])
            {
                if (y[j] < y[i])
                {
                    bit &= (15 - 1);
                }
                if (y[j] > y[i])
                {
                    bit &= (15 - 2);
                }
            }
            if (y[j] == y[i])
            {
                if (x[j] < x[i])
                {
                    bit &= (15 - 4);
                }
                if (x[j] > x[i])
                {
                    bit &= (15 - 8);
                }
            }
        }
        if (bit == 0)
        {
            supercentral += 1;
        }
    }
    cout << supercentral << endl;
    return 0;
}
// 165B
#4314087  Aug 20, 2013 4:53:51 AM    fuwutu   165B - Burning Midnight Oil     Python 3   Accepted    124 ms  0 KB
l = input().split(' ')
n, k = int(l[0]), int(l[1])
left, right = 1, n
while left != right:
    x = middle = (left + right) // 2
    sum = 0
    while x != 0:
        sum += x
        x //= k
    if sum >= n:
        right = middle
    else:
        left = middle + 1
print(left)
// 166A
//4042740   Jul 9, 2013 6:04:04 PM	fuwutu	 166A - Rank List	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

struct team
{
    int problems;
    int penaltytime;
};

bool cmp(const team& left, const team& right)
{
    return left.problems > right.problems
        || (left.problems == right.problems && left.penaltytime < right.penaltytime);
}

int main()
{
    int n, k;
    team t[50];
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i].problems >> t[i].penaltytime;
    }
    sort(t, t + n, cmp);
    k -= 1;
    int l(k), r(k);
    while (l > 0 && t[l-1].problems == t[k].problems && t[l-1].penaltytime == t[k].penaltytime)
    {
        l -= 1;
    }
    while (r + 1 < n && t[r+1].problems == t[k].problems && t[r+1].penaltytime == t[k].penaltytime)
    {
        r += 1;
    }
    cout << r - l + 1 << endl;
    return 0;
}
// 166E
//4324919	 Aug 22, 2013 8:27:14 PM	fuwutu	 166E - Tetrahedron	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>
#include <memory.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long a[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
    long long b[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            long long c[4][4] = {0};
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                    c[i][j] %= 1000000007LL;
                }
            }
            memcpy(b, c, sizeof(b));
        }

        long long c[4][4] = {0};
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 4; ++k)
                {
                    c[i][j] += a[i][k] * a[k][j];
                }
                c[i][j] %= 1000000007LL;
            }
        }
        memcpy(a, c, sizeof(a));

        n /= 2;
    }

    printf("%I64d\n", b[0][0]);
    return 0;
}
// 168A
//4033567   Jul 7, 2013 11:26:18 AM	fuwutu	 168A - Wizards and Demonstration	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int clones = (n * y + 99) / 100 - x;
    if (clones < 0)
    {
        clones = 0;
    }
    cout << clones << endl;
    return 0;
}
// 172A
//4059111   Jul 13, 2013 2:09:39 PM 	fuwutu 	172A - Phone Code 	GNU C++0x 	Accepted 	31 ms 	0 KB
#include <cstdio>
#include <cstring>

int main()
{
    int n;
    char s0[21], s[21];
    scanf("%d%s", &n, s0);
    int m = strlen(s0);
    while (--n)
    {
        scanf("%s", s);
        for (int i = 0; i < m; ++i)
        {
            if (s[i] != s0[i])
            {
                m = i;
                break;
            }
        }
    }
    printf("%d\n", m);
    return 0;
}
// 182B
#4314540	 Aug 20, 2013 9:13:16 AM	fuwutu	 182B - Vasya's Calendar	 Python 3	Accepted	 124 ms	 0 KB
d = int(input())
n = int(input())
l = input().split(' ')
times = 0
for i in range(0, n-1):
    times += d - int(l[i])
print(times)
// 186A
//4240233   Aug 7, 2013 4:37:55 PM	fuwutu	 186A - Строкосравнитель	 GNU C++0x	Accepted	 62 ms	 200 KB
#include <cstdio>
#include <cstring>

int main()
{
    char s1[100001], s2[100001];
    scanf("%s%s", s1, s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    bool same = false;
    if (len1 == len2)
    {
        int diff[3], diffcount(0);
        for (int i = 0; i < len1; ++i)
        {
            if (s1[i] != s2[i])
            {
                diff[diffcount++] = i;
                if (diffcount == 3)
                {
                    break;
                }
            }
        }
        if (diffcount == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]])
        {
            same = true;
        }
    }
    printf(same ? "YES\n" : "NO\n");

    return 0;
}
// 189A
//4240283   Aug 7, 2013 4:58:38 PM	fuwutu	 189A - Cut Ribbon	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, c, maximum(0);
    scanf("%d%d%d%d", &n, &a, &b, &c);

    bool x[4001] = {false}, y[8001] = {false};
    x[0] = true;
    for (int step = 1; ; ++step)
    {
        int count(0);
        for (int i = 0; i <= n; ++i)
        {
            if (x[i])
            {
                y[i+a] = true;
                y[i+b] = true;
                y[i+c] = true;
                count += 1;
            }
        }

        if (count == 0)
        {
            break;
        }

        copy(y, y + n + 1, x);
        fill(y, y + n + 1, false);

        if (x[n])
        {
            maximum = step;
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 190A
//4240283   Aug 7, 2013 4:58:38 PM	fuwutu	 189A - Cut Ribbon	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, c, maximum(0);
    scanf("%d%d%d%d", &n, &a, &b, &c);

    bool x[4001] = {false}, y[8001] = {false};
    x[0] = true;
    for (int step = 1; ; ++step)
    {
        int count(0);
        for (int i = 0; i <= n; ++i)
        {
            if (x[i])
            {
                y[i+a] = true;
                y[i+b] = true;
                y[i+c] = true;
                count += 1;
            }
        }

        if (count == 0)
        {
            break;
        }

        copy(y, y + n + 1, x);
        fill(y, y + n + 1, false);

        if (x[n])
        {
            maximum = step;
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 194A
//4238316   Aug 7, 2013 4:47:59 AM	fuwutu	 194A - Exams	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", k <= n * 3 ? n * 3 - k : 0);
    return 0;
}
// 194B
//4339876	 Aug 26, 2013 6:25:52 PM	fuwutu	 194B - Square	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%I64d", &n);
        if ((n + 1) % 4 == 0)
        {
            printf("%I64d\n", n + 1);
        }
        else if ((n + 1) % 2 == 0)
        {
            printf("%I64d\n", n * 2 + 1);
        }
        else
        {
            printf("%I64d\n", n * 4 + 1);
        }
    }
    return 0;
}
// 195A
#4324702	 Aug 22, 2013 7:41:39 PM	fuwutu	 195A - Let's Watch Football	 Python 3	Accepted	124 ms	0 KB
l = input().split(' ')
a, b, c = int(l[0]), int(l[1]), int(l[2])
d = ((a - b) * c + b - 1) // b
print(d)
// 199A
#4055616   Jul 12, 2013 7:40:42 PM	fuwutu	 199A - Hexadecimal's theorem	 Python 3	Accepted	78 ms	100 KB
n = int(input())
if n == 0:
    print(0, 0, 0)
else:
    a, b = 0, 1
    while a + b != n:
        a, b = b, a + b
    print(0, a, b)
    
// 200B
//4033618   Jul 7, 2013 11:40:55 AM	fuwutu	 200B - Drinks	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, p, total(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p;
        total += p;
    }
    cout << static_cast<double>(total) / static_cast<double>(n) << endl;
    return 0;
}
// 203A
//4172437   Jul 27, 2013 5:48:18 AM	fuwutu	 203A - Two Problems	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;
    if (x == 0)
    {
        cout << "YES" << endl;
        return 0;
    }

    if (x == 0
        || (x <= a && x > a - da * t && (a - x) % da == 0)
        || (x <= b && x > b - db * t && (b - x) % db == 0))
    {
        cout << "YES" << endl;
        return 0;
    }

    for (int pa = a, pb = b - db * (t - 1); pa > a - da * t && pb <= b; )
    {
        if (pa + pb > x)
        {
            pa -= da;
        }
        else if (pa + pb < x)
        {
            pb += db;
        }
        else
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
// 205A
//4035181   Jul 7, 2013 6:43:30 PM	fuwutu	 205A - Little Elephant and Rozdil	 GNU C++0x	Accepted	46 ms	0 KB
#include <cstdio>

using namespace std;

int main()
{
    int n, time, min_time(1000000001), min_index(0), count(1);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &time);
        if (time < min_time)
        {
            min_time = time;
            min_index = i;
            count = 1;
        }
        else if (time == min_time)
        {
            count += 1;
        }
    }
    if (count == 1)
    {
        printf("%d\n", min_index);
    }
    else
    {
        printf("Still Rozdil\n");
    }
    return 0;
}
// 208A
//4032897   Jul 7, 2013 5:34:34 AM	fuwutu	 208A - Dubstep	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<string> words;
    size_t start = 0;
    while (true)
    {
        size_t end = s.find("WUB", start);
        if (end == string::npos)
        {
            words.push_back(s.substr(start, end));
            break;
        }
        if (end != start)
        {
            words.push_back(s.substr(start, end - start));
        }
        start = end + 3;
    }

    if (!words.empty())
    {
        cout << words[0];
    }
    for (size_t i = 1; i < words.size(); ++i)
    {
        cout << " " << words[i];
    }
    cout << endl;

    return 0;
}
// 208D
//4263589   Aug 11, 2013 6:26:48 AM 	fuwutu 	208D - Prizes, Prizes, more Prizes 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <cstdio>

int main()
{
    int n, p[50], a, b, c, d, e, points(0), mug(0), towel(0), bag(0), bicycle(0), car(0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
    }
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    for (int i = 0; i < n; ++i)
    {
        points += p[i];

        car += points / e;
        points %= e;
        bicycle += points / d;
        points %= d;
        bag += points / c;
        points %= c;
        towel += points / b;
        points %= b;
        mug += points / a;
        points %= a;
    }
    printf("%I64d %I64d %I64d %I64d %I64d\n%d\n", mug, towel, bag, bicycle, car, points);
    return 0;
}
// 214A
//4032999   Jul 7, 2013 7:05:20 AM	fuwutu	 214A - System of Equations	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, m, answer(0);
    cin >> n >> m;

    for (int a = 0; a * a <= n && a <= m; ++a)
    {
        int b = n - a * a;
        if (a + b * b == m)
        {
            answer += 1;
        }
    }

    cout << answer << endl;
    return 0;
}
// 215A
//4034009   Jul 7, 2013 1:12:56 PM	fuwutu	 215A - Bicycle Chain	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, m, a[50], b, max(0), count(1);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> b;
        for (int j = 0; j < n; ++j)
        {
            if (b % a[j] == 0)
            {
                int x = b / a[j];
                if (x > max)
                {
                    max = x;
                    count = 1;
                }
                else if (x == max)
                {
                    count += 1;
                }
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
// 216A
//4055814   Jul 12, 2013 8:45:32 PM	fuwutu	 216A - Tiling with Hexagons	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a * b + b * c + c * a - a - b - c + 1 << endl;
    return 0;
}
// 218A
//4306429	 Aug 18, 2013 7:09:01 AM	fuwutu	 218A - Mountain Scenery	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>

int main()
{
    int n, k, r[201];
    scanf("%d%d%d", &n, &k, &r[0]);
    for (int i = 1; i <= n * 2; i += 2)
    {
        scanf("%d%d", &r[i], &r[i+1]);
        if (k > 0 && r[i] > r[i-1] + 1 && r[i] > r[i+1] + 1)
        {
            k -= 1;
            r[i] -= 1;
        }
    }
    printf("%d", r[0]);
    for (int i = 1; i <= n * 2; ++i)
    {
        printf(" %d", r[i]);
    }
    printf("\n");
    return 0;
}
// 218B
//4057689   Jul 13, 2013 7:39:37 AM	fuwutu	 218B - Airport	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, a[1000];
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + m);
    int minimum(0), num(a[0]), k(0);
    for (int i = 0; i < n; ++i)
    {
        minimum += num;
        num -= 1;
        if (num == 0)
        {
            num = a[++k];
        }
    }

    sort(a, a + m, greater<int>());
    int maximum(0);
    while (n--)
    {
        maximum += a[0];
        a[0] -= 1;
        for (int i = 1; i < m; ++i)
        {
            if (a[i] <= a[i-1])
            {
                break;
            }
            swap(a[i], a[i-1]);
        }
    }

    cout << maximum << " " << minimum << endl;
    return 0;
}
// 219A
//4033694   Jul 7, 2013 11:59:29 AM	fuwutu	 219A - k-String	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    string s;
    cin >> k >> s;

    int count[26] = {0};
    for (size_t i = 0; i < s.length(); ++i)
    {
        count[s[i]-'a'] += 1;
    }

    string s1;
    size_t c = 0;
    for (; c < 26; ++c)
    {
        if (count[c] % k != 0)
        {
            break;
        }
        else
        {
            s1.append(count[c] / k, 'a' + c);
        }
    }
    if (c == 26)
    {
        while (k--)
        {
            cout << s1;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
// 221A
//4033744   Jul 7, 2013 12:13:57 PM	fuwutu	 221A - Little Elephant and Function	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n;
    for (int i = 1; i < n; ++i)
    {
        cout << " " << i;
    }
    cout << endl;
    return 0;
}
// 221B
//4263403   Aug 11, 2013 5:31:52 AM 	fuwutu 	221B - Little Elephant and Numbers 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <iostream>

using namespace std;

bool digit[10] = {false};

void init(int n)
{
    while (n != 0)
    {
        digit[n % 10] = true;
        n /= 10;
    }
}

bool match(int n)
{
    while (n != 0)
    {
        if (digit[n % 10])
        {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main()
{
    int x;
    cin >> x;
    init(x);

    int d = 1, count(0);
    while (d * d < x)
    {
        if (x % d == 0)
        {
            if (match(d))
            {
                ++count;
            }
            if (match(x / d))
            {
                ++count;
            }
        }
        ++d;
    }
    if (d * d == x && match(d))
    {
        ++count;
    }
    cout << count << endl;
    return 0;
}
// 222A
//4035123   Jul 7, 2013 6:28:36 PM	fuwutu	 222A - Shooshuns and Sequence	 GNU C++0x	Accepted	31 ms	0 KB
#include <cstdio>

using namespace std;

int main()
{
    int n, k, a, last(0), continuous(1);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        if (a == last)
        {
            continuous += 1;
        }
        else
        {
            continuous = 1;
        }
        last = a;
    }
    printf("%d\n", continuous + k > n ? n - continuous: -1);
    return 0;
}
// 222B
//4236807   Aug 6, 2013 4:09:16 PM	fuwutu	 222B - Cosmic Tables	 GNU C++0x	Accepted	872 ms	3900 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int p[1001][1001], row[1001], col[1001];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int r = 1; r <= n; ++r)
        row[r] = r;

    for (int c = 1; c <= m; ++c)
        col[c] = c;

    for (int r = 1; r <= n; ++r)
        for (int c = 1; c <= m; ++c)
            scanf("%d", &p[r][c]);

    while (k--)
    {
        char s[2];
        int x, y;
        scanf("%s%d%d", s, &x, &y);
        switch (s[0])
        {
        case 'r':
            swap(row[x], row[y]);
            break;
        case 'c':
            swap(col[x], col[y]);
            break;
        case 'g':
            printf("%d\n", p[row[x]][col[y]]);
            break;
        default:
            break;
        }
    }
    return 0;
}
// 224A
//4033775   Jul 7, 2013 12:22:12 PM	fuwutu	 224A - Parallelepiped	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int ab, bc, ca;
    cin >> ab >> bc >> ca;
    int a = sqrt(ab * ca / bc + 0.5);
    int b = sqrt(bc * ab / ca + 0.5);
    int c = sqrt(ca * bc / ab + 0.5);
    cout << (a + b + c) * 4 << endl;
    return 0;
}
// 225A
//4042654   Jul 9, 2013 5:40:32 PM	fuwutu	 225A - Dice Tower	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    bool possible(true);
    int n, x, a, b;
    cin >> n >> x;
    while (n--)
    {
        cin >> a >> b;
        if (x == a || x == b || x == 7 - a || x == 7 - b)
        {
            possible = false;
        }
        x = 7 - x;
    }
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}
// 227B
//4263447   Aug 11, 2013 5:48:07 AM 	fuwutu 	227B - Effective Approach 	GNU C++0x 	Accepted 	92 ms 	400 KB
#include <cstdio>

int main()
{
    int n, a, index[100001];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        index[a] = i;
    }

    int m, b;
    scanf("%d", &m);
    long long Vasya(0), Petya(0);
    while (m--)
    {
        scanf("%d", &b);
        Vasya += index[b];
        Petya += (n + 1 - index[b]);
    }
    printf("%I64d %I64d\n", Vasya, Petya);
    return 0;
}
// 228A
//4021166   Jul 4, 2013 7:14:46 PM	fuwutu	 228A - Is your horseshoe on the other hoof?	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> s(4);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << 4 - s.size() << endl;
    return 0;
}
// 230A
//4032937   Jul 7, 2013 6:12:45 AM	fuwutu	 230A - Dragons	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <algorithm>

using namespace std;

struct dragon
{
    int x;
    int y;
};

bool cmp(const dragon& left, const dragon& right)
{
    return left.x < right.x;
}

int main()
{
    int s, n;
    cin >> s >> n;

    dragon d[10000];
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i].x >> d[i].y;
    }
    sort(d, d + n, cmp);

    int boss = d[n-1].x;
    for (int i = 0; i < n && s <= boss; ++i)
    {
        if (s > d[i].x)
        {
            s += d[i].y;
        }
        else
        {
            break;
        }
    }

    if (s > boss)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
// 230B
//4048435   Jul 11, 2013 3:30:44 AM	fuwutu	 230B - T-primes	 GNU C++0x	Accepted	78 ms	3100 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    bool notprime[1000000] = {false};
    for (int i = 3; i < 1000; i += 2)
    {
        if (!notprime[i])
        {
            int ii = i + i;
            for (int j = i + ii; j < 1000000; j += ii)
            {
                notprime[j] = true;
            }
        }
    }
    vector<long long> t_primes;
    t_primes.push_back(2*2);
    for (int i = 3; i < 1000000; i += 2)
    {
        if (!notprime[i])
        {
            t_primes.push_back(static_cast<long long>(i) * static_cast<long long>(i));
        }
    }
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long long x;
        scanf("%I64d", &x);
        printf("%s\n", binary_search(t_primes.begin(), t_primes.end(), x) ? "YES" : "NO");
    }

    return 0;
}
// 231A
//4006945   Jul 3, 2013 6:18:52 PM	fuwutu	 231A - Team	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, Petya, Vasya, Tonya, number(0);
    cin >> n;
    while (n--)
    {
        cin >> Petya >> Vasya >> Tonya;
        if (Petya + Vasya + Tonya >= 2)
        {
            number += 1;
        }
    }
    cout << number << endl;
    return 0;
}
// 233A
//4033107   Jul 7, 2013 8:03:16 AM	fuwutu	 233A - Perfect Permutation	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << "2 1";
        for (int i = 3; i < n; i += 2)
        {
            cout << " " << i + 1 << " " << i;
        }
        cout << endl;
    }
    return 0;
}
// 236A
//4022081   Jul 4, 2013 8:27:39 PM	fuwutu	 236A - Boy or Girl	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    if (s.length() % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
    return 0;
}
// 236B
//4306373	 Aug 18, 2013 6:53:30 AM	fuwutu	 236B - Easy Number Challenge	 GNU C++0x	Accepted	 62 ms	 0 KB
#include <cstdio>

int main()
{
    const int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int pfc[101][25] = {0};
    for (int i = 1; i <= 100; ++i)
    {
        int ii = i;
        for (int j = 0; ii != 1 && j < 25; ++j)
        {
            while (ii % primes[j] == 0)
            {
                pfc[i][j] += 1;
                ii /= primes[j];
            }
        }
    }

    int a, b, c, answer(0);
    scanf("%d%d%d", &a, &b ,&c);
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            for (int k = 1; k <= c; ++k)
            {
                int divisors = 1;
                for (int d = 0; d < 25; ++d)
                {
                    divisors *= (1 + pfc[i][d] + pfc[j][d] + pfc[k][d]);
                }
                answer += divisors;
            }
        }
    }
    answer %= 1073741824;
    printf("%d\n", answer);

    return 0;
}
// 237A
//4027473   Jul 5, 2013 6:52:44 PM	fuwutu	 237A - Free Cash	 GNU C++0x	Accepted	46 ms	0 KB
#include <stdio.h>

int main()
{
    int n, h, m, h0, m0, c(1), cash(1);
    scanf("%d", &n);
    scanf("%d%d", &h0, &m0);

    while (--n)
    {
        scanf("%d%d", &h, &m);
        if (h == h0 && m == m0)
        {
            c += 1;
            if (c > cash)
            {
                cash = c;
            }
        }
        else
        {
            c = 1;
        }
        h0 = h;
        m0 = m;
    }
    printf("%d\n", cash);
    return 0;
}
// 239A
//4057974   Jul 13, 2013 9:21:57 AM	fuwutu	 239A - Two Bags of Potatoes	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>

int main()
{
    int y, k, n;
    scanf("%d%d%d", &y, &k, &n);
    int x = k - y % k;
    int top = n - y;
    if (x <= top)
    {
        printf("%d", x);
        x += k;
        while (x <= top)
        {
            printf(" %d", x);
            x += k;
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
// 242A
//4052591   Jul 12, 2013 3:41:55 AM	fuwutu	 242A - Heads or Tails	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int count = 0;
    for (int Vasya = a; Vasya <= x; ++Vasya)
    {
        int end = min(Vasya - 1, y);
        if (b <= end)
        {
            count += (end - b + 1);
        }
    }
    cout << count << endl;
    for (int Vasya = a; Vasya <= x; ++Vasya)
    {
        int end = min(Vasya - 1, y);
        for (int Petya = b; Petya <= end; ++Petya)
        {
            cout << Vasya << " " << Petya << endl;
        }
    }
    return 0;
}
// 242B
//4048451   Jul 11, 2013 3:40:15 AM	fuwutu	 242B - Big Segment	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, l, r, minl, maxr, number(1);
    scanf("%d%d%d", &n, &minl, &maxr);
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d%d", &l, &r);
        if (l <= minl && r >= maxr)
        {
            number = i;
        }
        else if (l < minl || r > maxr)
        {
            number = -1;
        }
        minl = min(minl, l);
        maxr = max(maxr, r);
    }
    printf("%d\n", number);
    return 0;
}
// 244A
//4035355   Jul 7, 2013 7:39:20 PM	fuwutu	 244A - Dividing Orange	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, k, a[30];
    bool b[901] = {false};
    cin >> n >> k;
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
        b[a[i]] = true;
    }
    int d = 0;
    for (int i = 0; i < k; ++i)
    {
        cout << a[i];
        for (int j = 1; j < n; ++j)
        {
            ++d;
            while (b[d])
            {
                ++d;
            }
            cout << " " << d;
        }
        cout << endl;
    }
    return 0;
}
// 245A
//4057519   Jul 13, 2013 6:52:47 AM	fuwutu	 245A - System Administrator	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, t, x, y, xa(0), ya(0), xb(0), yb(0);
    cin >> n;
    while (n--)
    {
        cin >> t >> x >> y;
        if (t == 1)
        {
            xa += x;
            ya += y;
        }
        else
        {
            xb += x;
            yb += y;
        }
    }
    cout << (xa >= ya ? "LIVE" : "DEAD") << endl;
    cout << (xb >= yb ? "LIVE" : "DEAD") << endl;
    return 0;
}
// 245B
//4263640   Aug 11, 2013 6:44:25 AM 	fuwutu 	245B - Internet Address 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    size_t p = s.find('p');
    s.insert(p + 1, "://");

    size_t ru = s.find("ru", p + 5);
    if (ru + 2 != s.length())
    {
        s.insert(ru + 2, "/");
    }
    s.insert(ru, ".");

    cout << s << endl;
    return 0;
}
// 246A
//4033438   Jul 7, 2013 10:40:48 AM	fuwutu	 246A - Buggy Sorting	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 2)
    {
        for (int i = 2; i <= n; ++i)
        {
            cout << i << " ";
        }
        cout << 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
// 246B
//4058029   Jul 13, 2013 9:37:53 AM	fuwutu	 246B - Increase and Decrease	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <cstdio>

int main()
{
    int n, a, sum(0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        sum += a;
    }
    printf("%d\n", sum % n == 0 ? n : n - 1);
    return 0;
}
// 248A
//4034999   Jul 7, 2013 5:49:19 PM	fuwutu	 248A - Cupboards	 GNU C++0x	Accepted	15 ms	0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, l, r, left(0), right(0);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &l, &r);
        left += l;
        right += r;
    }
    printf("%d\n", min(left, n - left) + min(right, n - right));
    return 0;
}
// 252A
//4304419	 Aug 17, 2013 7:55:55 PM	fuwutu	 252A - Little Xor	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>

int main()
{
    int n, a, x[101] = {0};
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        x[i] = x[i-1] ^ a;
    }
    int maximal = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int xx = x[i] ^ x[j];
            if (xx > maximal)
            {
                maximal = xx;
            }
        }
    }
    printf("%d\n", maximal);
    return 0;
}
// 253A
//4059072   Jul 13, 2013 1:57:50 PM 	fuwutu 	253A - Boys and Girls 	GNU C++0x 	Accepted 	15 ms 	200 KB
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    size_t n, m;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;

    if (n >= m)
    {
        string s(n+m, 'B');
        for (size_t i = 1; i < m * 2; i += 2)
        {
            s[i] = 'G';
        }
        cout << s << endl;
    }
    else
    {
        string s(m+n, 'G');
        for (size_t i = 1; i < n * 2; i += 2)
        {
            s[i] = 'B';
        }
        cout << s << endl;
    }
    return 0;
}
// 254A
//4304346	 Aug 17, 2013 7:38:25 PM	fuwutu	 254A - Cards with Numbers	 GNU C++0x	Accepted	530 ms	4800 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    pair<int, int>* x = new pair<int, int>[n * 2];
    for (int i = 0; i < n * 2; ++i)
    {
        scanf("%d", &x[i].first);
        x[i].second = i + 1;
    }

    sort(x, x + n * 2);
    bool possible = true;
    for (int i = 0; i < n * 2; i += 2)
    {
        if (x[i].first != x[i+1].first)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        for (int i = 0; i < n * 2; i += 2)
        {
            printf("%d %d\n", x[i].second, x[i+1].second);
        }
    }
    else
    {
        printf("-1\n");
    }

    delete[] x;
    return 0;
}
//4304346	 Aug 17, 2013 7:38:25 PM	fuwutu	 254A - Cards with Numbers	 GNU C++0x	Accepted	530 ms	4800 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    pair<int, int>* x = new pair<int, int>[n * 2];
    for (int i = 0; i < n * 2; ++i)
    {
        scanf("%d", &x[i].first);
        x[i].second = i + 1;
    }

    sort(x, x + n * 2);
    bool possible = true;
    for (int i = 0; i < n * 2; i += 2)
    {
        if (x[i].first != x[i+1].first)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        for (int i = 0; i < n * 2; i += 2)
        {
            printf("%d %d\n", x[i].second, x[i+1].second);
        }
    }
    else
    {
        printf("-1\n");
    }

    delete[] x;
    return 0;
}


//4304381	 Aug 17, 2013 7:46:43 PM	fuwutu	 254A - Cards with Numbers	 GNU C++0x	Accepted	404 ms	6900 KB
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, a;
    vector<int> index[5001];
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; ++i)
    {
        scanf("%d", &a);
        index[a].push_back(i);
    }

    bool possible = true;
    for (int i = 1; i < 5001; ++i)
    {
        if (index[i].size() % 2 == 1)
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        for (int i = 1; i < 5001; ++i)
        {
            for (size_t j = 0; j < index[i].size(); j += 2)
            {
                printf("%d %d\n", index[i][j], index[i][j+1]);
            }
        }
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
//4033282   Jul 7, 2013 9:25:08 AM	fuwutu	 255A - Greg's Workout	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, chest(0), biceps(0), back(0);
    cin >> n;
    for (int i = 0; i < n / 3; ++i)
    {
        cin >> a >> b >> c;
        chest += a;
        biceps += b;
        back += c;
    }
    if (n % 3 == 1)
    {
        cin >> a;
        chest += a;
    }
    else if (n % 3 == 2)
    {
        cin >> a >> b;
        chest += a;
        biceps += b;
    }
    if (chest > biceps && chest > back)
    {
        cout << "chest" << endl;
    }
    else if (biceps > back && biceps > chest)
    {
        cout << "biceps" << endl;
    }
    else
    {
        cout << "back" << endl;
    }
    return 0;
}
// 255B
//4195173   Jul 28, 2013 6:14:10 PM	fuwutu	 255B - Code Parsing	 GNU C++0x	Accepted	156 ms	2100 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int nx(0), ny(0);
    for (char c : s)
    {
        if (c == 'x')
        {
            nx += 1;
        }
        else
        {
            ny += 1;
        }
    }
    if (nx > ny)
    {
        s.assign(nx - ny, 'x');
    }
    else
    {
        s.assign(ny - nx, 'y');
    }
    cout << s << endl;
    return 0;
}
// 257A
//4238335   Aug 7, 2013 5:09:13 AM	fuwutu	 257A - Sockets	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, m, k, a[50];
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n, greater<int>());
    int filters(0), plug(k);
    while (filters < n && plug < m)
    {
        plug += a[filters] - 1;
        filters += 1;
    }
    printf("%d\n", plug >= m ? filters : -1);
    return 0;
}
// 257B
//4266235   Aug 11, 2013 6:06:06 PM	fuwutu	 257B - Playing Cubes	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int Vasya = min(n, m);
    int Petya = n + m - 1 - Vasya;
    cout << Petya << " " << Vasya << endl;
    return 0;
}
// 259A
//4034927   Jul 7, 2013 5:30:43 PM	fuwutu	 259A - Little Elephant and Chess	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool fail(false);
    string s;
    for (int i = 0; i < 8; ++i)
    {
        cin >> s;
        for (size_t j = 1; j < s.length(); ++j)
        {
            if (s[j] == s[j-1])
            {
                fail = true;
            }
        }
    }
    cout << (fail ? "NO" : "YES") << endl;
    return 0;
}
// 259B
//4035330   Jul 7, 2013 7:30:59 PM	fuwutu	 259B - Little Elephant and Magic Square	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int x11, x12, x13, x21, x22, x23, x31, x32, x33;
    cin >> x11 >> x12 >> x13 >> x21 >> x22 >> x23 >> x31 >> x32 >> x33;
    int sum = (x12 + x13 + x21 + x23 + x31 + x32) / 2;
    x11 = sum - x12 - x13;
    x22 = sum - x21 - x23;
    x33 = sum - x31 - x32;
    cout << x11 << " " << x12 << " " << x13 << endl;
    cout << x21 << " " << x22 << " " << x23 << endl;
    cout << x31 << " " << x32 << " " << x33 << endl;
    return 0;
}
// 260A
//4076484   Jul 15, 2013 7:47:42 PM	fuwutu	 260A - Adding Digits	 GNU C++0x	Accepted	15 ms	100 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    bool exist(false);
    for (int i = 0; i < 10; ++i)
    {
        if ((a * 10 + i) % b == 0)
        {
            cout << a * 10 + i;
            string s(n - 1, '0');
            cout << s << endl;
            exist = true;
            break;
        }
    }
    if (!exist)
    {
        cout << -1 << endl;
    }
    return 0;
}
// 262A
//4033968   Jul 7, 2013 12:59:41 PM	fuwutu	 262A - Roma and Lucky Numbers	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, k, count(0);
    cin >> n >> k;

    string s;
    while (n--)
    {
        int lucky(0);
        cin >> s;
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (s[i] == '4' || s[i] == '7')
            {
                lucky += 1;
            }
        }
        if (lucky <= k)
        {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}
// 262B
#4286327	 Aug 16, 2013 3:35:51 PM	fuwutu	 262B - Roma and Changing Signs	 Python 3	Accepted	280 ms	5500 KB
l = input().split(' ')
n, k = int(l[0]), int(l[1])
l = input().split(' ')
answer = 0
m = 10000
for i in range(0, n):
    a = int(l[i])
    if (a >= 0):
        answer += a
        if a < m:
            m = a
    else:
        if k > 0:
            answer -= a
            k -= 1
        else:
            answer += a
        if -a < m:
            m = -a
if k % 2 == 1:
    answer -= m * 2
print(answer)
// 263A
//4027348   Jul 5, 2013 6:26:08 PM	fuwutu	 263A - Beautiful Matrix	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x = 0;
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            cin >> x;
            if (x == 1)
            {
                cout << abs(i - 3) + abs(j - 3) << endl;
            }
        }
    }
    return 0;
}
// 263B
//4033603   Jul 7, 2013 11:36:30 AM	fuwutu	 263B - Squares	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, a[50+1];
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    a[n] = 0;
    if (k > n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a[k-1] << " " << 0 << endl;
    }
    return 0;
}
// 264A
//4275242	 Aug 14, 2013 5:03:19 AM	fuwutu	 264A - Escape from Stones	 GNU C++0x	Accepted	 498 ms	 8800 KB
#include <cstdio>
#include <cstring>

char s[1000001];
int left[1000002];
int right[1000002];

int main()
{
    scanf("%s", s);
    int n = strlen(s);

    right[0] = n + 1;
    right[n + 1] = 0;

    int l = 0, r = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        right[l] = i;
        left[i] = l;

        right[i] = r;
        left[r] = i;

        switch (s[i-1])
        {
        case 'l':
            r = i;
            break;
        case 'r':
            l = i;
            break;
        default:
            break;
        }
    }

    int x = 0;
    while (n--)
    {
        x = right[x];
        printf("%d\n", x);
    }

    return 0;
}
// 265A
//4033637   Jul 7, 2013 11:44:53 AM	fuwutu	 265A - Colorful Stones (Simplified Edition)	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    size_t pos = 0;
    for (size_t i = 0; i < t.length(); ++i)
    {
        if (t[i] == s[pos])
        {
            pos += 1;
        }
    }
    cout << pos + 1 << endl;
    return 0;
}
// 265B
//4035298   Jul 7, 2013 7:23:30 PM	fuwutu	 265B - Roadside Trees (Simplified Edition)	 GNU C++0x	Accepted	31 ms	0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, h, h0(0);
    scanf("%d", &n);
    int time = n + n - 1;
    while (n--)
    {
        scanf("%d", &h);
        time += abs(h - h0);
        h0 = h;
    }
    printf("%d\n", time);
    return 0;
}
// 266A
//4007012   Jul 3, 2013 6:39:25 PM	fuwutu	 266A - Stones on the Table	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    string s;
    cin >> s;
    s.erase(unique(s.begin(), s.end()), s.end());
    cout << n - s.length() << endl;
    return 0;
}
// 266B
//4021768   Jul 4, 2013 7:57:17 PM	fuwutu	 266B - Queue at the School	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, t;
    string s;
    cin >> n >> t >> s;
    while (t--)
    {
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == 'G' && s[i-1] == 'B')
            {
                s[i] = 'B';
                s[i-1] = 'G';
                ++i;
            }
        }
    }
    cout << s << endl;
    return 0;
}
// 268A
//4021898   Jul 4, 2013 8:08:38 PM	fuwutu	 268A - Games	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int number(0);
    vector<int> h(n), a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i] >> a[i];
        for (int j = 0; j < i; ++j)
        {
            if (h[i] == a[j])
            {
                number += 1;
            }
            if (a[i] == h[j])
            {
                number += 1;
            }
        }
    }
    cout << number << endl;
    return 0;
}
// 268B
//4027723   Jul 5, 2013 7:56:08 PM	fuwutu	 268B - Buttons	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    // 1*(n-1)+1 + 2*(n-2)+1 + 3*(n-3)+1 + ... + n*(n-n)+1
    cout << (n - 1) * n * (n + 1) / 6 + n << endl;
    return 0;
}
// 268C
//4263502   Aug 11, 2013 6:01:01 AM 	fuwutu 	268C - Beautiful Sets of Points 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <cstdio>
#include <algorithm>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int k = std::min(n, m);
    printf("%d\n", k + 1);
    for (int i = 0; i <= k; ++i)
    {
        printf("%d %d\n", i, k - i);
    }
    return 0;
}
// 270A
//4032932   Jul 7, 2013 6:02:15 AM	fuwutu	 270A - Fancy Fence	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int t, a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (360 % (180 - a) == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
// 270B
//4189214   Jul 27, 2013 5:01:04 PM	fuwutu	 270B - Multithreading	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>

int main()
{
    int n, a0, a, ascending(1);
    scanf("%d%d", &n, &a0);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &a);
        if (a > a0)
        {
            ascending  += 1;
        }
        else
        {
            ascending = 1;
        }
        a0 = a;
    }
    printf("%d\n", n - ascending);
    return 0;
}
// 271A
//4022146   Jul 4, 2013 8:34:23 PM	fuwutu	 271A - Beautiful Year	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int y;
    cin >> y;
    while (true)
    {
        y += 1;
        int a = y / 1000;
        int b = y / 100 % 10;
        int c = y / 10 % 10;
        int d = y % 10;
        if (a != b && a != c && a != d && b != c && b != d && c != d)
        {
            break;
        }
    }
    cout << y << endl;
    return 0;
}
// 271B
//4236666   Aug 6, 2013 3:27:01 PM	fuwutu	 271B - Prime Matrix	 GNU C++0x	Accepted	 124 ms	 100 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    const size_t M = 100100;
    bool prime[M];
    prime[0] = false;
    prime[1] = false;
    fill(prime + 2, prime + M, true);
    for (int i = 2; i * i < M; ++i)
    {
        if (prime[i])
        {
            for (int j = i + i; j < M; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int n, m, a, rows[500], cols[500];
    scanf("%d%d", &n, &m);
    fill(rows, rows + n, 0);
    fill(cols, cols + m, 0);

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            scanf("%d", &a);
            int x = a;
            while (!prime[x])
            {
                ++x;
            }
            rows[r] += (x - a);
            cols[c] += (x - a);
        }
    }

    int min_row = *min_element(rows, rows + n);
    int min_col = *min_element(cols, cols + m);
    printf("%d\n", min(min_row, min_col));
    return 0;
}
// 272A
//4033146   Jul 7, 2013 8:27:46 AM	fuwutu	 272A - Dima and Friends	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, f, total(0), answer(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> f;
        total += f;
    }
    for (int i = 1; i <= 5; ++i)
    {
        if ((total + i) % (n + 1) != 1)
        {
            answer += 1;
        }
    }
    cout << answer << endl;
    return 0;
}
// 272B
//4265639   Aug 11, 2013 3:54:36 PM	fuwutu	 272B - Dima and Sequence	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>

using namespace std;

int bitcount(int n) 
{ 
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555) ; 
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333) ; 
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f) ; 
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff) ; 
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff) ; 
    return n ; 
}

int main()
{
    int n, a, c[32] = {0};
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        c[bitcount(a)] += 1;
    }

    long long answer = 0;
    for (size_t i = 0; i < sizeof(c) / sizeof(c[0]); ++i)
    {
        answer += static_cast<long long>(c[i]) * static_cast<long long>(c[i] - 1) / 2;
    }
    printf("%I64d\n", answer);
    return 0;
}
// 275A
//4033486   Jul 7, 2013 10:57:25 AM	fuwutu	 275A - Lights Out	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int x11, x12, x13, x21, x22, x23, x31, x32, x33;
    cin >> x11 >> x12 >> x13 >> x21 >> x22 >> x23 >> x31 >> x32 >> x33;
    cout << ((x11 + x12 + x21) % 2 == 0 ? "1" : "0") << ((x11 + x12 + x13 + x22) % 2 == 0 ? "1" : "0") << ((x12 + x13 + x23) % 2 == 0 ? "1" : "0") << endl;
    cout << ((x11 + x21 + x22 + x31) % 2 == 0 ? "1" : "0") << ((x12 + x21 + x22 + x23 + x32) % 2 == 0 ? "1" : "0") << ((x13 + x22 + x23 + x33) % 2 == 0 ? "1" : "0") << endl;
    cout << ((x21 + x31 + x32) % 2 == 0 ? "1" : "0") << ((x22 + x31 + x32 + x33) % 2 == 0 ? "1" : "0") << ((x23 + x32 + x33) % 2 == 0 ? "1" : "0") << endl;
    return 0;
}
// 276A
//4032976   Jul 7, 2013 6:40:04 AM	fuwutu	 276A - Lunch Rush	 GNU C++0x	Accepted	31 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, k, f, t, max_joy, joy;
    cin >> n >> k >> f >> t;
    if (t > k)
    {
        max_joy = f - (t - k);
    }
    else
    {
        max_joy = f;
    }
    while (--n)
    {
        cin >> f >> t;
        if (t > k)
        {
            joy = f - (t - k);
        }
        else
        {
            joy = f;
        }
        if (joy > max_joy)
        {
            max_joy = joy;
        }
    }
    cout << max_joy << endl;
    return 0;
}
// 276B
//4057570   Jul 13, 2013 7:06:56 AM	fuwutu	 276B - Little Girl and Game	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool odd[26] = {false};
    for (size_t i = 0; i < s.length(); ++i)
    {
        odd[s[i]-'a'] = !odd[s[i]-'a'];
    }
    int oddcount = count(odd, odd + sizeof(odd) / sizeof(odd[0]), true);
    cout << (oddcount == 0 || oddcount % 2 == 1 ? "First" : "Second") << endl;
    return 0;
}
// 276C
//4306317	 Aug 18, 2013 6:33:43 AM	fuwutu	 276C - Little Girl and Maximum Sum	 GNU C++0x	Accepted	218 ms	1500 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int a[200000], c[200001] = {0};

int main()
{
    int n, q, l, r;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    while (q--)
    {
        scanf("%d%d", &l, &r);
        c[l-1] += 1;
        c[r] -= 1;
    }
    for (int i = 1; i < n; ++i)
    {
        c[i] += c[i-1];
    }

    sort(a, a + n);
    sort(c, c + n);
    long long answer = 0;
    for (int i = 0; i < n; ++i)
    {
        answer += static_cast<long long>(a[i]) * static_cast<long long>(c[i]);
    }
    printf("%I64d\n", answer);
    return 0;
}
// 278A
//4032921   Jul 7, 2013 5:54:54 AM	fuwutu	 278A - Circle Line	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, d, f[100+2] = {0}, s, t;
    cin >> n;
    for (int i = 2; i < n + 2; ++i)
    {
        cin >> d;
        f[i] = f[i-1] + d;
    }
    cin >> s >> t;
    if (s > t)
    {
        swap(s, t);
    }
    int distance = f[t] - f[s];
    cout << min(distance, (f[n+1] - distance)) << endl;
    return 0;
}
// 278B
//4332589	 Aug 24, 2013 4:25:09 PM	fuwutu	 278B - New Problem	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <cstring>

int main()
{
    int n;
    char ch[30];
    bool exist1[26] = {false}, exist2[26][26] = {false};

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", ch);
        for (int j = 0; j < strlen(ch); ++j)
        {
            exist1[ch[j]-'a'] = true;
        }
        for (int j = 1; j < strlen(ch); ++j)
        {
            exist2[ch[j-1]-'a'][ch[j]-'a'] = true;
        }
    }

    bool found = false;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (!exist1[c-'a'])
        {
            printf("%c\n", c);
            found = true;
            break;
        }
    }

    if (!found)
    {
        for (char c1 = 'a'; !found && c1 <= 'z'; ++c1)
        {
            for (char c2 = 'a'; c2 <= 'z'; ++c2)
            {
                if (!exist2[c1-'a'][c2-'a'])
                {
                    printf("%c%c\n", c1, c2);
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}
// 279A
#4304263	 Aug 17, 2013 7:17:58 PM	fuwutu	 279A - The Point on the Spiral	 Python 3	Accepted	 124 ms	 0 KB
l = input().split(' ')
x, y = int(l[0]), int(l[1])
if y <= 0 and x >= 1 + y and x <= 1 - y:
    print((-y) * 4)
elif x > 0 and y >= 2 - x and y <= x:
    print(x * 4 - 3)
elif y > 0 and x >= -y and x <= y - 1:
    print(y * 4 - 2)
elif x < 0 and y >= x and y <= -1 - x:
    print((-x) * 4 - 1)
else:
    print(0)
// 279B
//4057901   Jul 13, 2013 8:57:44 AM	fuwutu	 279B - Books	 GNU C++0x	Accepted	31 ms	400 KB
#include <cstdio>

int main()
{
    int n, t, a[100000];
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    int j(0), time(0);
    while (j < n && time + a[j] <= t)
    {
        time += a[j++];
    }
    int maximum(j);
    for (int i = 0; i < n; ++i)
    {
        time -= a[i];
        while (j < n && time + a[j] <= t)
        {
            time += a[j++];
        }
        if (j - i - 1 > maximum)
        {
            maximum = j - i - 1;
        }
    }
    printf("%d\n", maximum);
    return 0;
}
// 281A
//4027326   Jul 5, 2013 6:20:12 PM	fuwutu	 281A - Word Capitalization	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    s[0] = towupper(s[0]);
    cout << s << endl;
    return 0;
}
// 282A
//4007122   Jul 3, 2013 7:08:49 PM	fuwutu	 282A - Bit++	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, x(0);
    cin >> n;

    string s;
    while (n--)
    {
        cin >> s;
        if (s[1] == '+')
        {
            ++x;
        }
        else
        {
            --x;
        }
    }

    cout << x << endl;
    return 0;
}
// 282B
//4058602   Jul 13, 2013 12:18:22 PM	fuwutu	 282B - Painting Eggs	 GNU C++0x	Accepted	484 ms	0 KB
#include <cstdio>

int main()
{
    int n, a, g;
    scanf("%d", &n);

    int A(0);
    while (n--)
    {
        scanf("%d%d", &a, &g);
        A += a;
        if (A <= 500)
        {
            printf("A");
        }
        else
        {
            A -= 1000;
            printf("G");
        }
    }
    printf("\n");

    return 0;
}
// 282C
//4237725   Aug 6, 2013 9:18:15 PM 	fuwutu 	282C - XOR and OR 	GNU C++0x 	Accepted 	280 ms 	3100 KB
#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    bool can(false);
    if (a.length() == b.length())
    {
        size_t ia(0), ib(0);
        while (ia < a.length() && a[ia] == '0')
            ++ia;
        while (ib < b.length() && b[ib] == '0')
            ++ib;
        if ((ia < a.length() && ib < b.length())
            || (ia == a.length() && ib == b.length()))
            can = true;
    }
    cout << (can ? "YES" : "NO") << endl;
    return 0;
}
// 284A
//4306626	 Aug 18, 2013 8:16:30 AM	fuwutu	 284A - Cows and Primitive Roots	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>

int main()
{
    int p, count(0);
    scanf("%d", &p);
    for (int n = 1; n < p; ++n)
    {
        bool ok = true;
        int x = 1;
        for (int i = 1; i < p - 1; ++i)
        {
            x *= n;
            x %= p;
            if (x == 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            x *= n;
            x %= p;
            if (x == 1)
            {
                count += 1;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}


//4306655	 Aug 18, 2013 8:36:13 AM	fuwutu	 284A - Cows and Primitive Roots	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>

int main()
{
    int p;
    scanf("%d", &p);
    int n = p - 1;
    int count = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            do
            {
                n /= i;
            } while (n % i == 0);
            count = count / i * (i - 1);
        }
    }
    if (n != 1)
    {
        count = count / n * (n - 1);
    }
    printf("%d\n", count);
    return 0;
}
// 284B
//4035087   Jul 7, 2013 6:20:05 PM	fuwutu	 284B - Cows and Poker Game	 GNU C++0x	Accepted	15 ms	200 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    char ch[200001];
    scanf("%d%s", &n, ch);
    int allin = count(ch, ch + n, 'A');
    int in = count(ch, ch + n, 'I');
    int folded = count(ch, ch + n, 'F');
    if (in == 1)
    {
        printf("1\n");
    }
    else if (in == 0)
    {
        printf("%d\n", allin);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
// 285A
//4033063   Jul 7, 2013 7:36:19 AM	fuwutu	 285A - Slightly Decreasing Permutations	 GNU C++0x	Accepted	31 ms	0 KB
#include <cstdio>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < k; ++i)
    {
        printf("%d ", n - i);
    }
    printf("1");
    for (int i = 2; i <= n - k; ++i)
    {
        printf(" %d", i);
    }
    printf("\n");

    return 0;
}
// 285B
//4035044   Jul 7, 2013 6:06:34 PM	fuwutu	 285B - Find Marble	 GNU C++0x	Accepted	46 ms	400 KB
#include <cstdio>

int main()
{
    int n, s, t, p[100000+1];
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &p[i]);
    }
    int step = 0;
    while (s != t && p[s] != 0)
    {
        int temp = p[s];
        p[s] = 0;
        s = temp;
        step += 1;
    }
    printf("%d\n", s == t ? step : -1);
    return 0;
}
// 285C
//4034133   Jul 7, 2013 1:47:35 PM	fuwutu	 285C - Building Permutation	 GNU C++0x	Accepted	140 ms	1100 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[300000];
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    long long result(0);
    for (int i = 0; i < n; ++i)
    {
        result += abs(i + 1 - a[i]);
    }
    printf("%I64d", result);

    return 0;
}
// 287A
//4034464   Jul 7, 2013 3:07:20 PM	fuwutu	 287A - IQ Test	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vs(4);
    for (size_t i = 0; i < 4; ++i)
    {
        cin >> vs[i];
    }

    bool pass = false;
    for (size_t top = 0; top <= 2 && !pass; ++top)
    {
        for (size_t left = 0; left <= 2; ++left)
        {
            int dot = 0;
            for (size_t r = 0; r < 2; ++r)
            {
                for (size_t c = 0; c < 2; ++c)
                {
                    if (vs[top+r][left+c] == '.')
                    {
                        dot += 1;
                    }
                }
            }
            if (dot != 2)
            {
                pass = true;
                break;
            }
        }
    }
    cout << (pass ? "YES" : "NO") << endl;
    return 0;
}
// 289A
//4124774   Jul 21, 2013 4:09:28 AM	fuwutu	 289A - Polo the Penguin and Segments	 GNU C++0x	Accepted	46 ms	0 KB
#include <cstdio>

int main()
{
    int n, k, l, r, s(0);
    scanf("%d%d", &n, &k);
    while (n--)
    {
        scanf("%d%d", &l, &r);
        s = (s + r - l + 1) % k;
    }
    printf("%d\n", (k - s) % k);
    return 0;
}
// 291A
//4033186   Jul 7, 2013 8:44:41 AM	fuwutu	 291A - Spyke Talks	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, id[1000];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> id[i];
    }
    sort(id, id + n);
    int pairs = 0;
    for (int i = 1; i < n; ++i)
    {
        if (id[i] != 0 && id[i] == id[i-1])
        {
            pairs += 1;
            if (i + 1 < n && id[i] == id[i+1])
            {
                pairs = -1;
                break;
            }
        }
    }
    cout << pairs << endl;
    return 0;
}
// 291B
//4057396   Jul 13, 2013 6:22:17 AM	fuwutu	 291B - Command Line Arguments	 GNU C++0x	Accepted	62 ms	100 KB
#include <iostream>

using namespace std;

int main()
{
    char s[100001];
    string lexeme;
    cin.getline(s, sizeof(s) / sizeof(s[0]));
    char* p = s;
    bool quote(false);
    while (*p != 0)
    {
        if (quote)
        {
            if (*p != '\"')
            {
                lexeme.push_back(*p);
            }
            else
            {
                cout << "<" << lexeme << ">" << endl;
                lexeme.clear();
                quote = false;
            }
        }
        else
        {
            if (*p == '\"')
            {
                quote = true;
            }
            else if (*p == ' ')
            {
                if (!lexeme.empty())
                {
                    cout << "<" << lexeme << ">" << endl;
                    lexeme.clear();
                }
            }
            else
            {
                lexeme.push_back(*p);
            }
        }
        ++p;
    }
    if (!lexeme.empty())
    {
        cout << "<" << lexeme << ">" << endl;
    }
    return 0;
}
// 294A
//4033248   Jul 7, 2013 9:12:31 AM	fuwutu	 294A - Shaass and Oskols	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, m, a[100+2], x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    while (m--)
    {
        cin >> x >> y;
        a[x-1] += (y - 1);
        a[x+1] += (a[x] - y);
        a[x] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}
// 296A
//4052601   Jul 12, 2013 3:50:47 AM	fuwutu	 296A - Yaroslav and Permutations	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int continuous(1), max_continuous(1);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i-1])
        {
            continuous += 1;
            if (continuous > max_continuous)
            {
                max_continuous = continuous;
            }
        }
        else
        {
            continuous = 1;
        }
    }
    cout << (max_continuous <= (n + 1) / 2 ? "YES" : "NO") << endl;
    return 0;
}
// 298A
//4205157   Jul 30, 2013 8:24:41 PM	fuwutu	 298A - Snow Footprints	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    size_t n;
    string s;
    cin >> n >> s;

    for (size_t i = 0; i < n; ++i)
    {
        if (s[i] != '.')
        {
            if (s[i] == 'R')
            {
                while (s[i] == 'R')
                {
                    ++i;
                }
                cout << i << " " << i + 1 << endl;
            }
            else
            {
                cout << i + 1 << " " << i << endl;
            }
            break;
        }
    }

    return 0;
}
// 298B
//4263324   Aug 11, 2013 5:07:31 AM 	fuwutu 	298B - Sail 	GNU C++0x 	Accepted 	62 ms 	300 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, sx, sy, ex, ey, time(-1);
    string wind;
    cin >> t >> sx >> sy >> ex >> ey >> wind;
    for (int i = 0; i < t; ++i)
    {
        switch (wind[i])
        {
        case 'E':
            if (sx < ex)
            {
                sx += 1;
            }
            break;
        case 'S':
            if (sy > ey)
            {
                sy -= 1;
            }
            break;
        case 'W':
            if (sx > ex)
            {
                sx -= 1;
            }
            break;
        case 'N':
            if (sy < ey)
            {
                sy += 1;
            }
            break;
        default:
            break;
        }
        if (sx == ex && sy == ey)
        {
            time = i + 1;
            break;
        }
    }
    cout << time << endl;
    return 0;
}
// 300A
//4034291   Jul 7, 2013 2:22:31 PM	fuwutu	 300A - Array	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it < 0)
        {
            cout << "1 " << *it << endl;
            arr.erase(it);
            break;
        }
    }

    bool found(false);
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        if (*it > 0)
        {
            found = true;
            cout << "1 " << *it << endl;
            arr.erase(it);
            break;
        }
    }

    if (!found)
    {
        cout << "2";
        int count = 0;
        for (vector<int>::iterator it = arr.begin(); count < 2;)
        {
            if (*it < 0)
            {
                cout << " " << *it;
                it = arr.erase(it);
                ++count;
            }
            else
            {
                ++it;
            }
        }
        cout << endl;
    }

    cout << arr.size();
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}
// 302A
//4076621   Jul 15, 2013 8:14:28 PM	fuwutu	 302A - Eugeny and Array	 GNU C++0x	Accepted	187 ms	0 KB
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, a, l, r, c(0), d(0);
    scanf("%d%d", &n, &m);
    while (n--)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            c += 1;
        }
        else
        {
            d += 1;
        }
    }
    int up = min(c, d) * 2;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        printf((r - l) % 2 == 1 && r - l < up ? "1\n" : "0\n");
    }
    return 0;
}
// 302B
//4436009	 Sep 9, 2013 6:53:39 PM	fuwutu	 302B - Eugeny and Play List	 GNU C++0x	Accepted	156 ms	400 KB
#include <cstdio>

int main()
{
    int n, m, s[100001];
    s[0] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int c, t;
        scanf("%d%d", &c, &t);
        s[i] = s[i-1] + c * t;
    }
    int song = 1;
    while (m--)
    {
        int v;
        scanf("%d", &v);
        while (v > s[song])
        {
            song += 1;
        }
        printf("%d\n", song);
    }
}
// 312A
//4263699   Aug 11, 2013 7:03:13 AM 	fuwutu 	312A - Whose sentence is it? 	GNU C++0x 	Accepted 	62 ms 	100 KB
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    char ch[101];
    cin.getline(ch, 101);

    string s;
    while (n--)
    {
        cin.getline(ch, 101);
        s.assign(ch);

        if (s.length() >= 5)
        {
            if (s.substr(s.length() - 5, 5) == "lala.")
            {
                if (s.substr(0, 5) == "miao.")
                {
                    cout << "OMG>.< I don't know!" << endl;
                }
                else
                {
                    cout << "Freda's" << endl;
                }
            }
            else
            {
                if (s.substr(0, 5) == "miao.")
                {
                    cout << "Rainbow's" << endl;
                }
                else
                {
                    cout << "OMG>.< I don't know!" << endl;
                }
            }
        }
        else
        {
            cout << "OMG>.< I don't know!" << endl;
        }
    }
    return 0;
}
// 313A
//4033204   Jul 7, 2013 8:52:56 AM	fuwutu	 313A - Ilya and Bank Account	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n >= 0)
    {
        cout << n << endl;
    }
    else
    {
        int a = n / 10;
        int b = n / 100 * 10 + n % 10;
        cout << max(a, b) << endl;
    }
    return 0;
}
// 313B
//4055457   Jul 12, 2013 6:54:18 PM	fuwutu	 313B - Ilya and Queries	 GNU C++0x	Accepted	109 ms	500 KB
#include <cstdio>
#include <cstring>

int main()
{
    char s[100001];
    int a[100001], m, l, r;

    scanf("%s%d", s, &m);
    int len = strlen(s);

    a[1] = 0;
    for (int i = 1; i < len; ++i)
    {
        if (s[i] == s[i-1])
        {
            a[i+1] = a[i] + 1;
        }
        else
        {
            a[i+1] = a[i];
        }
    }

    while (m--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l]);
    }
    return 0;
}
// 315A
//4278687 	Aug 14, 2013 8:29:33 PM 	fuwutu 	315A - Sereja and Bottles 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <cstdio>

int main()
{
    int n, a[1000], b[1000], c[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        c[b[i]] += 1;
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        c[b[i]] -= 1;
        if (c[a[i]] == 0)
        {
            count += 1;
        }
        c[b[i]] += 1;
    }
    printf("%d\n", count);
    return 0;
}
// 315B
//4215408   Aug 2, 2013 9:09:42 AM	fuwutu	 315B - Sereja and Array	 GNU C++0x	Accepted	 156 ms	 400 KB
#include <cstdio>

int main()
{
    int n, m, a[100001], t, v, x, y, q, increase(0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    while (m--)
    {
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            scanf("%d%d", &v, &x);
            a[v] = x - increase;
            break;

        case 2:
            scanf("%d", &y);
            increase += y;
            break;

        case 3:
            scanf("%d", &q);
            printf("%d\n", a[q] + increase);
            break;

        default:
            break;
        }
    }
}
// 316A1
//4215774   Aug 2, 2013 10:26:21 AM	fuwutu	 316A1 - Special Task (30 points)	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int letter[128] = {0}, zero = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 'A' && s[i] < 'K')
        {
            letter[s[i]] = 1;
        }
        else if (s[i] == '?')
        {
            zero += 1;
        }
    }

    int result = 1;
    int lettercount = accumulate(letter + 'A', letter + 'K', 0);
    if (lettercount > 0)
    {
        if (s[0] >= 'A' && s[0] < 'K')
        {
            result *= 9;
        }
        else
        {
            result *= 10;
        }
    }
    for (int i = 1; i < lettercount; ++i)
    {
        result *= (10 - i);
    }

    if (zero > 0 && s[0] == '?')
    {
        result *= 9;
        zero -= 1;
    }

    string padding(zero, '0');
    cout << result << padding << endl;
}
// 316A2
//4215779   Aug 2, 2013 10:27:41 AM	fuwutu	 316A2 - Special Task (70 points)	 GNU C++0x	Accepted	30 ms	300 KB
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int letter[128] = {0}, zero = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 'A' && s[i] < 'K')
        {
            letter[s[i]] = 1;
        }
        else if (s[i] == '?')
        {
            zero += 1;
        }
    }

    int result = 1;
    int lettercount = accumulate(letter + 'A', letter + 'K', 0);
    if (lettercount > 0)
    {
        if (s[0] >= 'A' && s[0] < 'K')
        {
            result *= 9;
        }
        else
        {
            result *= 10;
        }
    }
    for (int i = 1; i < lettercount; ++i)
    {
        result *= (10 - i);
    }

    if (zero > 0 && s[0] == '?')
    {
        result *= 9;
        zero -= 1;
    }

    string padding(zero, '0');
    cout << result << padding << endl;
}
// 317A
//4231314   Aug 5, 2013 9:18:30 AM  fuwutu  317A - Perfect Pair GNU C++0x   Accepted    62 ms   0 KB 
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long x, y, m;
    cin >> x >> y >> m;
    if (x >= m || y >= m)
    {
        cout << 0 << endl;
    }
    else
    {
        if (x <= 0 && y <= 0)
        {
            cout << -1 << endl;
        }
        else
        {
            if (x < y)
            {
                swap(x, y);
            }
            long long result(0);
            if (y < 0)
            {
                long long n = (-y) / x + 1;
                result += n;
                y += x * n;
            }
            while (x < m)
            {
                y += x;
                swap(x, y);
                result += 1;
            }
            cout << result << endl;
        }
    }
    return 0;
}
// 317B
//4430072	 Sep 8, 2013 5:45:06 AM	fuwutu	 317B - Ants	 GNU C++0x	Accepted	436 ms	100 KB
#include <cstdio>
#include <memory.h>

const int M = 64;

int main()
{
    int n, t, ants[M * 2 + 1][M * 2 + 1] = {0}, ants_temp[M * 2 + 1][M * 2 + 1];
    scanf("%d%d", &n, &t);
    ants[M][M] = n;
    bool find = (n != 0);
    while (find)
    {
        find = false;

        memset(ants_temp, 0, sizeof(ants_temp));

        for (int i = 0; i <= M * 2; ++i)
        {
            for (int j = 0; j <= M * 2; ++j)
            {
                if (ants[i][j] >= 4)
                {
                    find = true;
                    ants_temp[i-1][j] += ants[i][j] / 4;
                    ants_temp[i+1][j] += ants[i][j] / 4;
                    ants_temp[i][j-1] += ants[i][j] / 4;
                    ants_temp[i][j+1] += ants[i][j] / 4;
                }
                ants_temp[i][j] += ants[i][j] % 4;
            }
        }

        memcpy(ants, ants_temp, sizeof(ants));
    }

    while (t--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", (x >= -M && y >= - M && x <= M && y <= M) ? ants[M + x][M + y] : 0);
    }
    return 0;
}
// 318A
//4034903   Jul 7, 2013 5:22:04 PM	fuwutu	 318A - Even Odds	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k <= (n + 1) / 2)
    {
        cout << k * 2 - 1 << endl;
    }
    else
    {
        cout << (k - (n + 1) / 2) * 2 << endl;
    }
    return 0;
}
// 318B
//4240656   Aug 7, 2013 7:27:25 PM	fuwutu	 318B - Strings of Power	 GNU C++0x	Accepted	156 ms	2100 KB
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int heavy(0);
    long long amount(0);
    for (size_t i = 4; i < s.length(); ++i)
    {
        if (s[i] == 'l')
        {
            if (s[i-4] == 'm' && s[i-3] == 'e' && s[i-2] == 't' && s[i-1] == 'a')
            {
                amount += heavy;
            }
        }
        else if (s[i-4] == 'h' && s[i-3] == 'e' && s[i-2] == 'a' && s[i-1] == 'v' && s[i] == 'y')
        {
            ++heavy;
        }
    }
    cout << amount << endl;
    return 0;
}
// 320A
//4057462   Jul 13, 2013 6:34:24 AM	fuwutu	 320A - Magic Numbers	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, state(0);
    cin >> n;

    bool magic(true);
    while (n != 0)
    {
        int d = n % 10;
        n /= 10;

        if (d == 1)
        {
            state = 0;
        }
        else if (d == 4 && state < 2)
        {
            state = state + 1;
        }
        else
        {
            magic = false;
        }
    }
    if (state != 0)
    {
        magic = false;
    }
    cout << (magic ? "YES" : "NO") << endl;
    return 0;
}
// 322A
//4058132   Jul 13, 2013 10:10:07 AM	fuwutu	 322A - Ciel and Dancing	 GNU C++0x	Accepted	 15 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << n + m - 1 << endl;
    for (int i = 1; i <= m; ++i)
    {
        cout << "1 " << i << endl;
    }
    for (int i = 2; i <= n; ++i)
    {
        cout << i << " 1" << endl;
    }
}
// 322B
//4264440   Aug 11, 2013 11:04:58 AM	fuwutu	 322B - Ciel and Flowers	 GNU C++0x	Accepted	 62 ms	 0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned r, g, b;
    cin >> r >> g >> b;

    unsigned R(r % 3), G(g % 3), B(b % 3);
    unsigned amount(r / 3 + g / 3 + b / 3 + min(R, min(G, B)));
    if (   R == 2 && G == 2 && B == 0 && b != 0
        || G == 2 && B == 2 && R == 0 && r != 0
        || B == 2 && R == 2 && G == 0 && g != 0)
    {
        amount += 1;
    }
    cout << amount << endl;
    return 0;
}
// 327A
//4057739   Jul 13, 2013 7:54:54 AM	fuwutu	 327A - Flipping Game	 GNU C++0x	Accepted	15 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    int n, a, count1(0), extra0(0), extra0max(-1);
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a == 1)
        {
            count1 += 1;
            if (extra0 > 0)
            {
                extra0 -= 1;
            }
        }
        else
        {
            extra0 += 1;
            if (extra0 > extra0max)
            {
                extra0max = extra0;
            }
        }
    }
    cout << count1 + extra0max << endl;
    return 0;
}
// 327B
#4076363   Jul 15, 2013 7:24:55 PM	fuwutu	 327B - Hungry Sequence	 Python 3	Accepted	 312 ms	 100 KB
import sys
n = int(input())
sys.stdout.write(str(n))
for i in range(n+1, n*2):
    sys.stdout.write(" " + str(i))
// 330A
//4172001     Jul 27, 2013 4:19:28 AM 	fuwutu 	330A - Cakeminator 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int r, c, row[11] = {0}, col[11] ={0};
    string s;
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
    {
        cin >> s;
        for (int j = 0; j < c; ++j)
        {
            if (s[j] == 'S')
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    int cakes(0);
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                cakes += 1;
            }
        }
    }
    cout << cakes << endl;
    return 0;
}
// 330B
//4225560   Aug 4, 2013 5:26:26 AM	fuwutu	 B - Road Construction	 GNU C++0x	Accepted	30 ms	0 KB
#include <cstdio>

int main()
{
    int n, m, a, b;
    bool fire[1001] = {false};
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d", &a, &b);
        fire[a] = true;
        fire[b] = true;
    }
    int x = 1;
    while (fire[x])
    {
        x++;
    }
    printf("%d\n", n - 1);
    for (int i = 1; i < x; ++i)
    {
        printf("%d %d\n", i, x);
    }
    for (int i = x + 1; i <= n; ++i)
    {
        printf("%d %d\n", x, i);
    }
    return 0;
}
// 332A
//4236727   Aug 6, 2013 3:44:49 PM	fuwutu	 332A - Down the Hatch!	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, glasses(0);
    string s;
    cin >> n >> s;
    for (int i = n; i < s.length(); i += n)
    {
        if (s[i-1] == s[i-2] && s[i-2] == s[i-3])
        {
            ++glasses;
        }
    }
    cout << glasses << endl;
    return 0;
}
// 333A
//4188836   Jul 27, 2013 4:31:25 PM	fuwutu	 333A - Secrets	 GNU C++0x	Accepted	30 ms	0 KB
#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    while (n % 3 == 0)
    {
        n /= 3;
    }

    cout << n / 3 + 1 << endl;
    return 0;
}
// 333B
//4188914   Jul 27, 2013 4:36:49 PM	fuwutu	 333B - Chips	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    int n, m, x, y, row[1001], col[1001];
    scanf("%d%d", &n, &m);
    fill(row + 1, row + n + 1, 1);
    fill(col + 1, col + n + 1, 1);

    while (m--)
    {
        scanf("%d%d", &x, &y);
        row[x] = 0;
        col[y] = 0;
    }

    int points = accumulate(row + 2, row + n, 0) + accumulate(col + 2, col + n, 0);
    if (n >= 3 && n % 2 == 1 && row[n / 2 + 1] == 1 && col[n / 2 + 1] == 1)
    {
        points -= 1;
    }

    printf("%d\n", points);
    return 0;
}
// 334A
//4175632   Jul 27, 2013 12:40:22 PM	fuwutu	 334A - Candy Bags	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d", i + 1);
        for (int j = 1; j < n; ++j)
        {
            printf(" %d", n * j + (i + j) % n + 1);
        }
        printf("\n");
    }
    return 0;
}
// 334B
//4175632   Jul 27, 2013 12:40:22 PM	fuwutu	 334A - Candy Bags	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d", i + 1);
        for (int j = 1; j < n; ++j)
        {
            printf(" %d", n * j + (i + j) % n + 1);
        }
        printf("\n");
    }
    return 0;
}
// 335A
//4331873	 Aug 24, 2013 1:46:14 PM	fuwutu	 335A - Banana	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>
#include <cstring>

int main()
{
    char s[1000];
    int n, count1[128] = {0}, count2[128] = {0};
    
    scanf("%s%d", s, &n);
    for (int i = 0; i < strlen(s); ++i)
    {
        count1[s[i]] += 1;
    }

    int letters = 0;
    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (count1[i] != 0)
        {
            letters += 1;
        }
    }

    if (letters <= n)
    {
        while (n--)
        {
            int numerator = 1001, denominator = 1, index = 0;
            for (int i = 'a'; i <= 'z'; ++i)
            {
                if (count1[i] != 0)
                {
                    if (count2[i] * denominator < numerator * count1[i])
                    {
                        numerator = count2[i];
                        denominator = count1[i];
                        index = i;
                    }
                }
            }
            count2[index] += 1;
        }

        int sheets = 0;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (count2[i] != 0)
            {
                int temp = (count1[i] + count2[i] - 1) / count2[i];
                if (temp > sheets)
                {
                    sheets = temp;
                }
            }
        }
        printf("%d\n", sheets);

        for (int i = 'a'; i <= 'z'; ++i)
        {
            while (count2[i]--)
            {
                printf("%c", i);
            }
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
// 336A
//4259668   Aug 10, 2013 8:56:45 AM	fuwutu00:06	 336A - Vasily the Bear and Triangle	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x > 0)
    {
        if (y > 0)
        {
            cout << 0 << " " << x + y << " " << x + y << " " << 0 << endl;
        }
        else
        {
            cout << 0 << " " << y - x << " " << x - y << " " << 0 << endl;;
        }
    }
    else
    {
        if (y > 0)
        {
            cout << x - y << " " << 0 << " " << 0 << " " << y - x << endl;;
        }
        else
        {
            cout << x + y << " " << 0 << " " << 0 << " " << x + y << endl;;
        }
    }
    return 0;
}
// 336B
//4262082   Aug 10, 2013 7:07:20 PM	fuwutu	 336B - Vasily the Bear and Fly	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double m, R;
    cin >> m >> R;

    double answer = (m * (m + 1) * (m + 2) / 3 - m) * 2;
    answer += (sqrt(2.0) - 2) * ((m * m - m) + (m * m - m - (m - 1) * 2));
    answer /= (m * m);

    answer *= R;
    cout << setprecision(7) << answer << endl;
    return 0;
}
// 336C
//4331596	 Aug 24, 2013 12:22:08 PM	fuwutu	 336C - Vasily the Bear and Sequence	 GNU C++0x	Accepted	 124 ms	 400 KB
#include <cstdio>

int main()
{
    int n, a[100000], count[32] = {0};
    bool b[32][32] = {false};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        int x = a[i], index = 0, zero[32], zerocount = 0;
        while (x != 0)
        {
            if (x % 2 == 1)
            {
                count[index] += 1;
                for (int j = 0; j < zerocount; ++j)
                {
                    b[index][zero[j]] = true;
                }
            }
            else
            {
                zero[zerocount++] = index;
            }
            x /= 2;
            index += 1;
        }
    }

    int v = 31;
    for (;;)
    {
        int j = 0;
        for (; j < v; ++j)
        {
            if (!b[v][j])
            {
                break;
            }
        }
        if (j == v)
        {
            break;
        }
        --v;
    }
    int k = count[v];
    printf("%d\n", k);

    int pv = 1 << v;
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] & pv) != 0)
        {
            printf((--k != 0 ? "%d " : "%d\n"), a[i]);
        }
    }

    return 0;
}
// 337A
//4300351 	Aug 17, 2013 4:18:19 AM 	fuwutu 	337A - Puzzles 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, f[1000];
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> f[i];
    }
    sort(f, f + m);
    int least = f[n-1] - f[0];
    for (int i = 1; i <= m - n; ++i)
    {
        if (f[i+n-1] - f[i] < least)
        {
            least = f[i+n-1] - f[i];
        }
    }
    cout << least << endl;
    return 0;
}
// 337B
#4302271	 Aug 17, 2013 12:41:50 PM	fuwutu	 337B - Routine Problem	 Python 3	Accepted	 92 ms	 0 KB
def gcd(a, b):
    while a % b != 0:
        a, b = b, a % b
    return b

l = input().split(' ')
a, b, c, d = int(l[0]), int(l[1]), int(l[2]), int(l[3])
if a * d > b * c:
    p = a * d - b * c
    q = a * d
else:
    p = b * c - a * d
    q = b * c
e = gcd(p, q)
p //= e
q //= e
print(str(p) + "/" + str(q))
// 337C
//4302392	 Aug 17, 2013 1:03:52 PM	fuwutu	 337C - Quiz	 GNU C++0x	Accepted	 62 ms	 0 KB
#include <iostream>

using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long wrong = n - m;
    if ((wrong + 1) * (k - 1) >= m)
    {
        cout << m << endl;
    }
    else
    {
        long long consecutive = m - wrong * (k - 1);
        long long t = consecutive / k;
        long long result = 1;
        long long pow = 2;
        long long tt = t;
        while (tt != 0)
        {
            if (tt % 2 == 1)
            {
                result *= pow;
                result %= 1000000009LL;
            }
            tt /= 2;
            pow = pow * pow % 1000000009LL;
        }
        result = ((result - 1) * 2 * k+ m - t * k) % 1000000009LL;
        cout << result << endl;
    }
    return 0;
}
// 337E
//4300331 	Aug 17, 2013 4:07:55 AM 	fuwutu 	337E - Divisor Tree 	GNU C++0x 	Accepted 	30 ms 	0 KB
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long long a[8], c[8];
int b[8] = {0};

void search(int n, int i, bool extra, int s, int& m)
{
    if (i + 1 < n)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (c[j] % a[i] == 0)
            {
                c[j] /= a[i];
                if (b[i] != 1)
                {
                    search(n, i + 1, extra, s + 1, m);
                }
                else
                {
                    search(n, i + 1, extra, s, m);
                }
                c[j] *= a[i];
            }
        }
        if (b[i] != 1)
        {
            search(n, i + 1, true, s + b[i] + 1, m);
        }
        else
        {
            search(n, i + 1, true, s + b[i], m);
        }
    }
    else
    {
        if (b[n-1] != 1)
        {
            s += b[n-1] + 1;
        }
        else
        {
            s += b[n-1];
        }
        if (extra)
        {
            s += 1;
        }
        if (s < m)
        {
            m = s;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    for (int i = 0; i < n; ++i)
    {
        c[i] = a[i];
        long long x = a[i];
        while (x % 2 == 0)
        {
            x /= 2;
            b[i] += 1;
        }
        for (long long j = 3; j * j <= x; j += 2)
        {
            while (x % j == 0)
            {
                x /= j;
                b[i] += 1;
            }
        }
        if (x != 1)
        {
            b[i] += 1;
        }
    }

    int m = accumulate(b, b + n, n + 1);
    search(n, 0, false, 0, m);

    cout << m << endl;

    return 0;
}
// 339A
#4362738	 Aug 28, 2013 6:54:41 PM	fuwutu	 339A - Helpful Maths	 Python 3	Accepted	 92 ms	 0 KB
s = input()
n1 = n2 = n3 = 0
for i in range(0, len(s), 2):
    if s[i] == '1':
        n1 += 1
    elif s[i] == '2':
        n2 += 1
    else:
        n3 += 1
ss = "1+" * n1 + "2+" * n2 + "3+" * n3
print(ss[:-1])
// 339B
//4362875	 Aug 28, 2013 7:34:17 PM	fuwutu	 339B - Xenia and Ringroad	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>

int main()
{
    int n, m, a0, a, cycle = 0;
    scanf("%d%d%d", &n, &m, &a0);
    while (--m)
    {
        scanf("%d", &a);
        if (a0 > a)
        {
            cycle += 1;
        }
        a0 = a;
    }
    printf("%I64d\n", static_cast<long long>(n) * static_cast<long long>(cycle) + a0 - 1);
    return 0;
}
// 340A
#4387236	 Aug 31, 2013 3:00:19 PM	fuwutu	 340A - The Wall	 Python 3	Accepted	 124 ms	 0 KB
def GCD(a, b):
    while a % b != 0:
        a, b = b, a % b
    return b

def LCM(a, b):
    return a * b // GCD(a, b)

l = input().split(' ')
x, y, a, b = int(l[0]), int(l[1]), int(l[2]), int(l[3])
lcm = LCM(x, y)
print(b // lcm - (a - 1) // lcm)
// 342A
//4592917	 Sep 28, 2013 4:40:12 AM	fuwutu	 342A - Xenia and Divisors	 GNU C++0x	Accepted	62 ms	0 KB
#include <cstdio>

int main()
{
    int n, x, count[8] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        count[x] += 1;
    }

    bool solution;
    if (count[5] == 0 && count[7] == 0 && count[2] >= count[4] && count[1] == count[4] + count[6] && count[2] + count[3] == count[4] + count[6])
    {
        for (int i = 0; i < count[4]; ++i)
        {
            printf("1 2 4\n");
        }
        count[2] -= count[4];
        for (int i = 0; i < count[2]; ++i)
        {
            printf("1 2 6\n");
        }
        for (int i = 0; i < count[3]; ++i)
        {
            printf("1 3 6\n");
        }
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
// 344A
//4592799	 Sep 28, 2013 4:08:58 AM	fuwutu	 344A - Magnets	 GNU C++0x	Accepted	 30 ms	 0 KB
#include <cstdio>

int main()
{
    int n, groups(0);
    scanf("%d", &n);

    char s[3], c('\0');
    while (n--)
    {
        scanf("%s", s);
        if (s[0] != c)
        {
            groups += 1;
        }
        c = s[0];
    }

    printf("%d\n",groups);
    return 0;
}

#include "../exercise.h"
#include <cmath>

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
template<typename T>
T plus(T a, T b) {
    return a + b;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    // TODO: 修改判断条件使测试通过
    ASSERT((std::fabs(plus(0.1f, 0.2f) - 0.3f) < 1e-6f), "How to make this pass?");

    return 0;
}
/**
 * @note 例如 1 在二进制中是 1，0.5 在二进制中是 0.1，0.25 在二进制中是 0.01。
 * 因此，此处的 1、2、3.75 都是可以精确表示的浮点数，于是就可以使用 == 判等。
 * 而 0.1 + 0.2 = 0.3 则是标准的不可判等的情况。因此判断条件要修改为误差和小于指定的界限。
 * 
 */

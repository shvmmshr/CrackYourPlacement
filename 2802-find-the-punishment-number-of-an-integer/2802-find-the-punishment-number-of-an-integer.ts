function punishmentNumber(n: number): number {
    let sum = 0;
    for (let i = 1; i <= n; ++i) {
        const square = i ** 2;
        sum += helper(square, i) ? square : 0;
    }
    return sum;
};

function helper(num: number, delta: number): boolean {
    if (delta < 0) {
        return false;
    }
    if (num == 0) {
        return delta == 0;
    }
    for (let place = 1; num > 0; place *= 10) {
        const mod = num % 10;
        num = (num - mod) / 10;
        delta -= mod * place;
        if (helper(num, delta)) {
            return true;
        }
    }
    return false;
}
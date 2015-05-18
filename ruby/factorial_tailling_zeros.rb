# @param {Integer} n
# @return {Integer}
def trailing_zeroes(n)
    res = 0
    while (n != 0) do
        res += (n / 5) 
        n /= 5
    end
    res
end

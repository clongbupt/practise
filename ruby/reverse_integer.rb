# @param {Integer} x
# @return {Integer}
def reverse(x)
    return 0 if x == 0
    flag = x > 0 ? 1 : -1
    tmp = (x * flag).to_s.reverse.to_i
    return 0 if tmp > 2 ** 31 - 1
    tmp * flag
end

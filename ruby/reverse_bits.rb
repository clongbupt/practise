# @param {Integer} n, a positive integer
# @return {Integer}
def reverse_bits(n)
    return 0 if n == 0
    n.to_s(2).rjust(32, '0').reverse.to_i(2)
end

# @param {Integer} n, a positive integer
# @return {Integer}
def hamming_weight(n)
    return 0 if n == 0
    n.to_s(2).count('1')
end

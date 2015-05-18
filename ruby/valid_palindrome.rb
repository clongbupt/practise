# @param {String} s
# @return {Boolean}
def is_palindrome(s)
    return true if s.size == 0
    s= s.gsub(/[^a-zA-Z0-9]/, "").downcase
    s == s.reverse
end

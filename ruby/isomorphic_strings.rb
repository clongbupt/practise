# @param {String} s
# @param {String} t
# @return {Boolean}
def is_isomorphic(s, t)
    return false if s.size != t.size
    
    h1 = {}
    h2 = {}
    
    (0...s.size).each do |i|
        c1 = s[i]
        c2 = t[i]
        
        if h1[c1].nil?
            h1[c1] = c2
        elsif h1[c1] != c2
            return false
        end
        
        if h2[c2].nil?
            h2[c2] = c1
        elsif h2[c2] != c1
            return false
        end
    end
    
    return true
end

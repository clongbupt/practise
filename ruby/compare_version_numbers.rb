# @param {String} version1
# @param {String} version2
# @return {Integer}
def compare_version(version1, version2)
    a1 = version1.split('.')
    a2 = version2.split('.')
    
    len = a1.size >= a2.size ? a1.size : a2.size
    (0...len).each do |i|
        if a1[i].nil? && a2[i].nil?
            return 0
        elsif a1[i].nil? && a2 =~ /[123456789]/
            return -1
        elsif a2[i].nil? && a1 =~ /[123456789]/
            return 1
        elsif a1[i].to_i > a2[i].to_i
            return 1
        elsif a1[i].to_i < a2[i].to_i
            return -1
        else
            next
        end
    end
    
    0
end

puts compare_version("1", "1.0")
puts compare_version("1", "1.0.1")
puts compare_version("1.0", "1.10")

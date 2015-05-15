# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)
    return nums[0] if nums.size == 1
    c = 1
    i = 1
    num = nums[0]
    while i < nums.size do
        if num == nums[i]
            c += 1
        elsif c > 0
            c -= 1
        else 
            num = nums[i]
            c = 1
        end    
        i += 1
    end
    
    num
end

puts majority_element([1,2,3,3,3,3,6])
puts majority_element([1,1])
puts majority_element([1,3,1])
puts majority_element([6,5,5])

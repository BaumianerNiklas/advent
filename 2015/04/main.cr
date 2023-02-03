require "digest/md5"


def find(num_zeros : Int)
	input = "bgvyzdsv";
	digest = Digest::MD5.new
	
	found = false
	i = 0
	until found
		i += 1
		digest << "#{input}#{i}"
	
		hash = digest.hexfinal
		if hash.starts_with?("0" * num_zeros)
			p! i, hash
			return
		end
		digest.reset
	end
end

find 5
find 6
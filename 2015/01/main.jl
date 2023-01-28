function solve()
	file = readline("./input.txt")
	floor = 0
	i = 0
	negative_at = 0

	for c ∈ file
		i += 1
		floor += c == '(' ? 1 : -1
		floor < 0 && negative_at == 0 && (negative_at = i)
	end
	
	println(floor)
	println("Negative at $negative_at")
end

@time solve()
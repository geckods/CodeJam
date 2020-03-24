toreadfile = false
ans = []

if toreadfile
  filename = "A-large.in"  
  file = File.read(filename).split("\n")
  i = 0
  t = file[i].to_i
  nparr = []
  prefixarr = []

  t.times do
    i += 1
    np = file[i].split(" ").map(&:to_i)
    minipref = []
    nparr.push np
    p = np[1]
    p.times do
      i+=1
      minipref.push file[i]
    end
    prefixarr.push minipref
  end
else
  t = gets.to_i
end

answers = []

def formoflength(n,lengtharr)
  counts = Hash.new(0)
  ans = 0

  lengtharr.uniq.each do |len|
    counts[len] = lengtharr.count(len)
  end

  asd = 2-counts[1]
  if asd==0
    return 0
  end

=begin  

  lengtharr.uniq.each do |len|

    if len==n
      ans = formoflength(n-1,lengtharr)
      return ans*2-counts[n]
    end

    ans += (2**(n-len))*(formoflength(len,lengtharr))
  end

=end
  
  (2..n).each do |x|
    asd = asd*2
    asd = asd-counts[x]
  end  
  

  return asd
end




#=begin
(0..t-1).each do |test|
  if toreadfile
    np = nparr[test]
    prefix = prefixarr[test]
    n = np[0]
    p = np[1]
  else
    np = gets.chomp.split(" ").map(&:to_i)
    n = np[0]
    p = np[1]
    prefix = []
    p.times do
      prefix.push gets.chomp
    end
  end

  todelete = []
  prefix.each_with_index do |a,i|
    prefix.each_with_index do |b,j|
      next if i==j
      if (b.length>=a.length) and b[0..a.length-1]==a
        todelete.push b
      end
    end
  end
  prefix = prefix - todelete


  lengths = prefix.map{|x| x.length}

  ans = formoflength(n,lengths)

  answers.push ans
end

answers.each_with_index do |ans,i|
  puts "Case ##{i+1}: #{ans}"
end
#=end

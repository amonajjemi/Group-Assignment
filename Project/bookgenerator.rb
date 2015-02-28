require 'isbndb'
require 'awesome_print'
require 'forgery'
require 'faker'

# Randomly merges two arrays
# While preserving the order
# Returns the resulting array
def ordered_random_merge(a,b)
  a, b = a.dup, b.dup
  a.map{rand(b.size+1)}.sort.reverse.each do |index|
    b.insert(index, a.pop)
  end
  b
end

# Really messy, pls dont kill me
# It works, thats all we need

books_results = Array.new
books = Array.new

ISBNdb::Query.find_books_by_title("and").each do |result|
  books_results << result.title
end

books = ordered_random_merge(books, books_results)
books_results.clear

ISBNdb::Query.find_books_by_title("the").each do |result|
  books_results << result.title
end

books = ordered_random_merge(books, books_results)
books_results.clear

ISBNdb::Query.find_books_by_title("with").each do |result|
  books_results << result.title
end

books = ordered_random_merge(books, books_results)
books_results.clear

ISBNdb::Query.find_books_by_title("by").each do |result|
  books_results << result.title
end

books = ordered_random_merge(books, books_results)
books_results.clear

ISBNdb::Query.find_books_by_title("for").each do |result|
  books_results << result.title
end

books = ordered_random_merge(books, books_results)
books_results.clear

ISBNdb::Query.find_books_by_title("if").each do |result|
  books_results << result.title
end

books = ordered_random_merge(books, books_results)
ap books

# Create a new file and write to it  
counter = 0
File.open('books.txt', 'w') do |file|  
	50.times do
		isbn = rand.to_s[2..14] 
		title = books[counter]
		first_name = Forgery('name').first_name
		last_name = Forgery('name').last_name
		publisher = Forgery('name').company_name
	  file.puts isbn + " '" + title + "' " + last_name + ", " + first_name + " " + publisher
	  counter += 1
	end
end  

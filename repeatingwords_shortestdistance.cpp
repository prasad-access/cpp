/*Program to find the shortest distance between repeating words. If no repeating words are found return -1 
  Time complexity : O(n)
  Space complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;


int shortestDistance(const std::vector<std::string>& words) {
	unordered_map<string,int> wordIndices;
	bool foundRepeatingWord = false;
	int minDistance = INT_MAX;
	
	for(int i=0;i<words.size();i++)
	{
	    string word = words[i];
	    if(wordIndices.find(word) != wordIndices.end())
	    {
	        foundRepeatingWord = true;
	        minDistance = std::min(minDistance, i - wordIndices[word] -1 );
	    }
	    
	    wordIndices[word] = i;
	}
	
	return foundRepeatingWord?minDistance:-1;
}

int main() {
	std::vector<std::string> words = {"all", "work", "and", "no", "play", "makes", "for", "no", "fun", "and", "no", "result", "at", "all"};
	int distance = shortestDistance(words);
	std::cout << "Shortest distance between repeating words: " << distance << std::endl;
	return 0;
}

import pronouncing as pro
import os
import random

text = "My name is poop I eat soup Fidget spinner throw your mom through a hoop mom tom"
text = "Python is a widely used high-level programming language for general-purpose programming, created by Guido van Rossum and first released in 1991. An interpreted language, Python has a design philosophy that emphasizes code readability notably using whitespace indentation to delimit code blocks rather than curly brackets or keywords, and a syntax that allows programmers to express concepts in fewer lines of code than might be used in languages such as C++ or Java. The language provides constructs intended to enable writing clear programs on both a small and large scale."

rhymes = {}

def findRhymes():
    words = text.split()
    for i in range(len(words)):#word in words:
        word = words[i]
        r = pro.rhymes(word)[:1]
        if len(r) > 0:
            phrase = ""
            n = random.randint(2, 5)
            if i-n >=0:
                phrase = " ".join(words[i-n+1:i+1])

            else: 
                phrase = word
            #print word + " " + r[0]
            if r[0] not in rhymes:
                arr = [phrase]
                rhymes[r[0]] = arr
            else:
                rhymes[r[0]].append(phrase)
                #print rhymes[r[0]]

"""def getPhrases():
    for key in rhymes:
        if len(rhymes[key]) > 1:
                """
            
    
    
    
    
    
findRhymes()
#print rhymes

        #rhymes[r]=word
#os.system("say 'test'")
done = ""
out = ""
for key in rhymes:
    if len(rhymes[key]) > 1:
        for rhyme in rhymes[key]:
            out += rhyme + ". "
    #t+=". "
    #os.system("say 'key'" )
    #done += " ".join(rhymes[key])
 #   done+= ". "
    #print key + " " + str(rhymes[key])
    #print str(rhymes[key])
#print rhymes
print out
os.system("say \"%s\" -v Zarvox" % out)

#print rhymes
"""
find all the rhymes, make array of each rhyme string with the 1-8 words before it
"""
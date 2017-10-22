# MICHELLE CAPLIN WROTE THIS SWAG 4 SD H4X (LILLIAN, WILLOW, KAREN)

import pronouncing as pro
import os
import random
import re
import wikipedia
import sys

if len(sys.argv) < 2:
    print "Choose a topic, homie"
    exit(0)
text = ""  
#intro = "" 
    
    
def GetArticle():
    article = sys.argv[1]

    results = wikipedia.search(article)

    i = 1
    p = ""

    try:
        p = wikipedia.summary(sys.argv[1], sentences=10)
    except:
        while(i < len(results)):
            try: 
                p = wikipedia.summary(results[i], sentences=10)
            except: 
                i+=1
            finally:
                topic = results[i]
                #intro = results[i] + ": A Rap auto-generated from Wikipedia with Wiki-Rap-App\n"
                p = wikipedia.summary(results[i], sentences=10)
                break
    else:
        topic = sys.argv[1]
        #intro = sys.argv[1] + ": A Rap auto-generated from Wikipedia with Wiki-Rap-App\n"
        p = wikipedia.summary(sys.argv[1], sentences=10)
    return p, topic
        
    



def FindRhymes(text):
    rhymes = {}
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
    return rhymes


"""
text = "I am ok with your excellent egg puns, I don't exaggerate my utter joy that I cannot explain. This is not a joke"          


def getEggPuns():
    words = text.split()
    for i in range(len(words)):
        word = words[i]
        word = re.sub(r'(\.*)ex(\.*)', '\1eggs\2', word)
        word = re.sub(r'(\.*)j*ok(\.*)', '\1yolk\2', word)
        words[i] = word
    return " ".join(words)
print text + "\n\n\n"
print getEggPuns()
    """
    
    
    


def MakeRap(rhymes, topic):
    rap = topic + ": A sick rap auto-generated from Wikipedia with Wiki-Rap-App.\n"
    for key in rhymes:
        if len(rhymes[key]) > 1:
            x = [[i] for i in range(len(rhymes[key]))]
            random.shuffle(x)
            inarow = 0
            last_rhyme = ""
            for j in range(len(rhymes[key])):
                rhyme = rhymes[key][j]
                r_list = rhyme.split()
                r = r_list[len(r_list)-1]
                if last_rhyme == r:
                    inarow += 1
                else:
                    inarow = 0
                last_rhyme = r
                if inarow < 1:
                    rap += rhyme + ". \n"
    return rap
                  
                  
def main():  
    text, topic = GetArticle()
    rhymes = FindRhymes(text)
    rap = MakeRap(rhymes, topic)
    out_file = open(topic + "-rap.txt", "w")
    #out_file.write(rap)
    #out_file.close()
    rap = rap.split("\n")
    for line in rap:
        line = line.encode('utf-8')
        #print line
        out_file.write(line + "\n")
    out_file.close()
    for line in rap:
        try:
            os.system("say '%s' " % line)
        except:
            next

main()

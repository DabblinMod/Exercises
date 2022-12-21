def to_camel_case(text):
    #your code here
    textList=""
    newStr=''
    if(text==''):
        return ''
    elif(len(text) > 0):
        sep=[' ', '-', '_', ','] #separators
        """Sep list is there for a text if it has a separator."""
        """We use sep to find the separator within the text then we split the text into a list"""
        for i in range(len(sep)): #loop will check each separator and remove them from text
            if(sep[i] in text): #so we must update the text parameter each time we find a separator
                text=text.replace(sep[i], ' ')#replaces each separator with space so we can make a list of words
        textList=text.split() #creates a list of the words using spaces
        for i in range(len(textList)):
            if(i>0 and textList[i][0] != textList[i][0].upper()):
                print("Text edit into Camel Case: ", textList[i][0].upper() + textList[i][1:])
                newStr+=textList[i][0].upper() + textList[i][1:]
            else:
                newStr+=textList[i]
    print(f"New Text is: {newStr}")
    return newStr
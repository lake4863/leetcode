# Crime and Punishment Python Excersise Notes

## Changes
1. In[3] line 3: changed from “print(text[0:100])” to “print(text[0:1000])”;

1. In[5] line 3: added 
'''Python
for t in text:
    i = text.index(t)
    if i < 502 and i > 498:
        print(i, t)
print(text[500])
print(text[499])
print(text[501])
'''

1. In[7] line 6: added 
'''Python
print(counts)
'''

1. In[8] line 4: added
'''
print('There are %s unique words using Counter from collections' % len(counts))
'''

1. In[9] line 3: changed: from print(english[0:15]) to print(english[0:25])

1. In[10] line 6: changed: from print('A few c&p words missing from the english dictionary: %s' % str(list(missing)[0:10])) to print('A few c&p words missing from the english dictionary: %s' % str(list(missing)[0:20]))

1. In[12] line 3: added
'''
print('The lenght of text variable as string: %s' % len(str(b)))
'''

1. In[13] line 6: added
'''
print(html[0:200])
'''

1. In[14] line 4: added
'''
print(raw[0:120])
'''

1. In[16] line 3: added
'''
print(tokens[14:25])
'''

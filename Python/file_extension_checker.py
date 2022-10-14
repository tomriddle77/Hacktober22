file = input('File name: ')

if file.lower().strip().endswith('.gif'):
    print('image/gif')

elif file.lower().strip().endswith('.jpg'):
    print('image/jpeg')

elif file.lower().strip().endswith('.jpeg'):
    print('image/jpeg')

elif file.lower().strip().endswith('.png'):
    print('image/png')

elif file.lower().strip().endswith('.pdf'):
    print('application/pdf')

elif file.lower().strip().endswith('.txt'):
    print('text/plain')

elif file.lower().strip().endswith('.zip'):
    print('application/zip')

else:
    print('application/octet-stream')
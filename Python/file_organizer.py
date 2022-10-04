# This script will allow you to categorically sort out your completely messed up directory (like your downloads folder).
# On running this script you can cateogorize a directory into media folder, installation folder, zip folder, image folder, and document folder.
# This script uses the os and shutil libraries.


import os
import shutil

# here the 'src' variable stores the path to the folder you want to sort

src = r"C:\Users\Alvin\Downloads"

dest_media = src + "\\Media_files"
dest_exe = src + "\\Installation_Files"
dest_img = src + "\\Image_Files"
dest_zip = src + "\\Zip"
dest_doc = src + "\\Documents"

for file in os.listdir(src):
    extension = os.path.splitext(file)[1]
    if extension in [".exe", ".msi"]:
        if not os.path.exists(dest_exe):
            os.makedirs(dest_exe)
        if not os.path.exists(dest_exe+"\\"+file):
            shutil.move(src+"\\"+file, dest_exe)
        else:
            os.remove(dest_exe+"\\"+file)
            shutil.move(src+"\\"+file, dest_exe)

    elif extension in [".mp4", ".avi", ".mov", ".mp3", ".mkv"]:
        if not os.path.exists(dest_media):
            os.makedirs(dest_media)
        if not os.path.exists(dest_media+"\\"+file):
            shutil.move(src+"\\"+file, dest_media)
        else:
            os.remove(dest_media+"\\"+file)
            shutil.move(src+"\\"+file, dest_media)

    elif extension in [".jpg", ".jpeg", ".png", ".svg", ".jfif"]:
        if not os.path.exists(dest_img):
            os.makedirs(dest_img)
        if not os.path.exists(dest_img+"\\"+file):
            shutil.move(src+"\\"+file, dest_img)
        else:
            os.remove(dest_img+"\\"+file)
            shutil.move(src+"\\"+file, dest_img)

    elif extension in [".pdf", ".doc", ".docx", ".ppt", ".pptx", ".xlsx", ".csv", ".epub", ".odt", ".txt"]:
        if not os.path.exists(dest_doc):
            os.makedirs(dest_doc)
        if not os.path.exists(dest_doc+"\\"+file):
            shutil.move(src+"\\"+file, dest_doc)
        else:
            os.remove(dest_doc+"\\"+file)
            shutil.move(src+"\\"+file, dest_doc)

    elif extension in [".7z", ".zip", ".rar"]:
        if not os.path.exists(dest_zip):
            os.makedirs(dest_zip)
        if not os.path.exists(dest_zip+"\\"+file):
            shutil.move(src+"\\"+file, dest_zip)
        else:
            os.remove(dest_zip+"\\"+file)
            shutil.move(src+"\\"+file, dest_zip)

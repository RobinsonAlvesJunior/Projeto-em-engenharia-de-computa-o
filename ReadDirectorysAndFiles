import sys
from os.path import expanduser
import pandas as pd
from PyQt4 import QtGui
import os
import re

def main():

    listDirectory()

def listDirectory():
    directory = QtGui.QFileDialog.getExistingDirectory(None, 'Select a folder:', expanduser("~"))
    fileList = [os.path.normcase(f)
                for f in os.listdir(directory)]

    print fileList

    pattern_Names_Files = re.compile(r"imagens.*")

    for i in range(len(fileList)):
        if pattern_Names_Files.search(fileList[i]) != None:

            image_location_directory = str(directory) + '\\' + str(fileList[i])
            print image_location_directory


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    main_window = main()
    sys.exit(app.exec_())

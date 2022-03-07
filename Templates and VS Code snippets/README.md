# VS Code Competitive Programming Templates

Copy-paste into user snippets for the language.


In settings.json add:


"editor.snippetSuggestions": "top"


or in settings search "snippet" and change Snippet Suggestions to "top"

# How to include <bits/stdc++.h>

If you're on Mac:

1. On Finder, Go -> Go To Folder (cmd+shift+G) -> /usr/local/include/
2. Create new folder, name it "bits" (without quotation marks)
3. Open TextEdit (or any other text editor), turn the file into a plain text file (cmd+shift+T), copy paste contents of stdc++.h (included in this repo) in the file, save it as anything, anywhere you want, for now
4. Move the untitled text file into the bits folder
5. Rename the text file to "stdc++.h" (without quotation marks), click on "Use .h" when prompted
6. Done

PS: If this doesn't work, go to /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 (just copy paste into Spotlight Search, and a folder named v1 should come up), create a new folder, name it "bits" and copy the stdc++.h file into there.
If that still doesn't work, contact an officer.

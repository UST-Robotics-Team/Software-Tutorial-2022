# Git Basics [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425.svg)](https://hackmd.io/LobT9mNYQJCZ3b7TbnDRQA?view)

#### Original author: Johnathan
Modified by Henry Loi (hchloi@connect.ust.hk)

*Reference from HKUST-Robotics-Team-SW-Tutorial-2021*

This document aims to provide the reader with a sense of how the git version control system works and provide a simple, hands-on demonstration. Git is complex and this tutorial only demonstrates the basic essentials.

## Overview

### What is Git and GitHub?
- Git is a free and open source distributed **version control system** designed to handle everything from small to very large projects with speed and efficiency.
- GitHub is designed as a **Git repository hosting service**. You can share your code and giving other users to make revisions and edits.

### Basic Workflow
![](https://i.ytimg.com/vi/0nqJKEh3YCc/maxresdefault.jpg)

0. You and your friend clone a repository from GitHub. A  *local copy* now exists on both your machines.
1. You make changes in your IDE.
2. You **add** and **commit** those changes. The *local* repo now registers this commit.
3. You **push** your changes. The *online* (aka remote) repo now shows these changes.
4. Your friend **pulls** your changes. Their *local copy* now shows those changes. To clarify, before pulling, your friend still had the copy from the beginning (no change). But after pulling, the local copy is updated.

### Conflict/Merge Workflow
0. You and your friend clone a repository.
1. You **and your friend** make changes.
2. You add and commit your changes.
3. Your friend **add**s and **commit**s their changes.
4. You push your changes.
5. Your friend **pulls** your changes.
6. Your friend **merges** the code. This may require a closer inspection and decision into each conflict.

## Terminology
Most definitions provided simplify the concepts a bit in an attempt to make them digestable. (Some were copied from online.) Google the term for more details (e.g. "git push").

### Repository (repo)
A centralised place to store files and resources. (Kinda like Google Drive or Dropbox.)

### Commit
(n.) A commit is a revision, an individual change to a file (or a set of files). These revisions are tracked by a unique ID (a hash).

To commit (v.) a change (or a file, or something) means to create a commit (n.). In most cases, this commit will only be stored in the local repository until you push.

### Clone
Copy the contents of a repository (normally to your local side).

### Checkout
Navigate between branches and commits. Your local repository will be updated.

### Push
Upload your local commits to the remote (online) repository.

### Pull
Download the remote repository and update your local repository.

### Branches
Branches allow you to make commit and push while maintaining independence from other people's commits.
![](https://www.nobledesktop.com/image/gitresources/git-branches-merge.png)

You can think of the default branch (normally called *master*) as the tree trunk, and other branches would branch off and diverge with their own changes.

### Merge
When two branches are combined together. The changes from the incoming branch is applied to the current branch. If a file could not be resolved, a **merge conflict** will occur.

## Working
There are multiple ways of working with Git. If your repo is on Github, you can edit text files directly in the Github editor. However, it is often more convenient to work with a local IDE.

Locally, you can directly use Git commands in the terminal. Another (often visually more convenient) way is to use a Git client, which is typically software designed to interface with the Git terminal commands. Some examples of Git clients are:

* [Github Desktop](https://desktop.github.com/): Minimal, works well with Github repos
* [Sourcetree](https://www.sourcetreeapp.com/): Complete, many buttons
* Git Graph: VSCode extension
* Sublime Merge
* Git Kraken

You can try them out to see which one suits you. For the purpose of this document, we'll stick to Github Desktop. Any other client should be able to do what Github Desktop can do.

If you're using the terminal, you can find documentation for a command by typing `man git <command>` or `git <command> --help`.

You can try out the following steps by creating a new repo solely for testing and playing around with. (To create a repo, click the <kbd>+</kbd> icon at the top right.) For the shell examples, we'll be using a fake `Example` repo. You can replace this with a repo of your choice.

### Setup Workflow
There are several ways to setup a Github repository. Here we'll just focus on cloning a repository from online.

First you'll want to clone the repository.


#### 1. Github Desktop (Suggested)
1. Click the green <kbd>Code</kbd> button.
2. Click <kbd>Open with Github Desktop</kbd>.
![](https://i.imgur.com/VOGlO0e.png)

3. Specify a local path (default is ok).
4. Press <kbd>Clone</kbd>.
![](https://i.imgur.com/NXuXP2z.png)


#### 2. Shell
This shell command will clone the repository to a folder in the current directory. The folder will have the same name as the repo.
```sh
git clone https://github.com/HKUST-Robotics-Team/Example
```

You can add a second path to specify a folder to clone to.
```sh
git clone https://github.com/HKUST-Robotics-Team/Example path/to/your/repo
```


### Development Workflow - Commit
Perhaps you've made some changes on the local side. Maybe you edited some code, moved some files or deleted some junk. It's time to sync up the remote repo with your local copy.

But first we need to update our local repository with the changes. Let's make a commit.

#### 1. Github Desktop (Suggested)

1. Check which files you want to commit.
2. Write a commit message. This is sometimes pre-generated.
3. Write a commit description (optional).
4. Press <kbd>Commit to ...</kbd>. (Ctrl/Cmd + Enter)

![](https://i.imgur.com/SE5H53a.png)
#### 2. Shell
At this point, it is crucial that your current directory is in the repo.

```sh
cd path/to/your/repo
```

You can run `pwd` to check that you're in the right folder and run `git status` to check that you're in a git environment.

> ```
> % pwd
> /Users/Robotics/Documents/path/to/your/repo
> 
> % git status
> On branch main
> Your branch is up to date with 'origin/main'.
>
> nothing to commit, working tree clean
> ```

When making commits, generally the process follows:
```sh
git add .
git commit -m "(sensible message, preferrably describing what you changed and why)"
```
`git add` *stages* your files, selecting them for a commit. The files haven't been committed yet, but they have been selected. We git add `.` to add modified files in the *current directory*. You can be more selective and select individual files or folders by specifying them (e.g. `git add main.cpp`, `git add some-folder/`).

`git commit` *commits* your staged files. We use the `-m` flag, followed by a string, to write a commit message. Typically, commit messages should describe what changes you've made in the commit and why you've made them.

### Development Workflow - Push
Now you want to upload your changes to the remote repository.

#### 1. Github Desktop

1. Press the push button in the top row. (Ctrl/Cmd + P)
2. If there are no merge conflicts and you have a stable connection, you're done!

![](https://i.imgur.com/swtCg3E.png)

#### 2. Shell
Simplest command:
```
git push
```
If there are no merge conflicts and you have a stable connection, you're done!



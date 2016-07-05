cd /projects/www.andrewallen.co.uk/
git clone git://github.com/imathis/octopress.git octopress
rm octopress/.rvmrc
rm octopress/.rbenv-version
cd octopress
bundle install
rake install


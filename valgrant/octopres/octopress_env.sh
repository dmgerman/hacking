#!/usr/bin/env bash
apt-get update && apt-get install -y git curl
curl -L https://get.rvm.io | bash -s stable --ruby=1.9.3
source /usr/local/rvm/scripts/rvm
rvm rubygems latest
gem install bundler

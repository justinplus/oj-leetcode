#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize_level(TreeNode* root) {
      stringstream ss;
      queue<TreeNode*> q;
      if(root) q.push(root);

      TreeNode *nd;
      while( !q.empty() ) {
        nd = q.front();
        q.pop();
        if( nd ) {
          ss << nd->val;
          q.push(nd->left);
          q.push(nd->right);
        } else {
          ss << '#';
        }
        ss<<',';
      }

      string str = ss.str();
      int pos = str.size()-1;
      for( ; pos >=0 && ( str[pos] == '#' || str[pos] == ',' ); --pos);

      return ss.str().substr(0, pos + 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize_level(string data) {
      stringstream ss(data);
      queue<TreeNode*> q;
      TreeNode *root = nullptr, *cur;

      int val, status;
      if( next(ss,val) != -1 ) {
        root = new TreeNode(val);
        q.push(root);
      }

      while( !q.empty() ) {
        cur = q.front();
        q.pop();

        if( ( status = next(ss, val) ) == -1 ) {
          break;
        } else if( status == 1 ) {
          q.push( new TreeNode(val) );
          cur->left = q.back();
        }

        if( ( status = next(ss, val) ) == -1 ) {
          break;
        } else if( status == 1 ) {
          q.push( new TreeNode(val) );
          cur->right = q.back();
        }
      }

      return root;
    }

    // `-1` for EOF, '0' for null node, '1' for non-null node
    static int next(stringstream &ss, int &val) {
      if( ss.peek() == char_traits<char>::eof() )
        return -1;
      else if( ss.peek() == '#' ) {
        ss.ignore(2);
        return 0;
      } else {
        ss >> val;
        ss.ignore(1);
        return 1;
      }
    }
};

// TODO: try other serialization methods

int test_next() {
  string data = "1,2,3,#,#,4";
  stringstream ss( data );
  int val;
  while( Codec::next(ss, val) != -1 ) cout<<val<<' ';
  cout<<endl;
  return 0;
}

int main() {
  TreeNode * r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  r->right->left = new TreeNode(4);
  r->right->right = new TreeNode(5);

  Codec codec;
  string data;
  data = codec.serialize_level(r);
  cout<<data<<endl;
  TreeNode * rr = codec.deserialize_level( data );

  cout<<rr->val<<endl;
  cout<<rr->left->val<<endl;
  cout<<rr->right->val<<endl;
  cout<<rr->right->left->val<<endl;
  cout<<rr->right->right->val<<endl;

  return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

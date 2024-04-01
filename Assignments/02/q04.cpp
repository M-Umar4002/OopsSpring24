#include <iostream>
#include <vector>
using namespace std;

class Post {
    int id, likes, totalComments, views;
    string content;
    vector<string> comments;
    
    public :
        Post() {}
        
        Post(int id, string content) : id(id), content(content), likes(0), totalComments(0), views(0) {}
    
        void addComment(string comment) {
            totalComments++;
            comments.push_back(comment);
        }
        
        void likePost() {
            likes++;
        }
        
        void setLikes(int likes) {
            this->likes = likes;
        }
        
        void setViews(int views) {
            this->views = views;
        }
        
        int getLikes() const {
            return likes;
        }
        
        int getTotalComments() const {
            return totalComments;
        }
        
        int getViews() const {
            return views;
        }
        
        void displayDetails() {
            cout << endl << "Id : " << id << endl << "Content : " << content << endl << "Likes : " << likes << endl << "Total Views : " << views << endl << "Total Comments : " << totalComments << endl;
            
            for(int i = 0; i < comments.size(); i++) {
                if(!i) cout << "Comments : " << endl;
                cout << "   Comment " << i+1 << " : " << comments[i] << endl;
            }
            
            views++;
        }
};

class User {
    string name, email, password;
    
    string encryptPassword(string password) {
        string encryptedPassword = "";
        
        for(char character : password) encryptedPassword += character+1;
        
        return encryptedPassword;
    }
    
    public : 
        User(string name, string email, string password) : name(name), email(email), password(encryptPassword(password)) {}
        
        bool verifyUser(string name, string email, string password) {
            return this->name == name && this->email == email && this->password == password;
        }
};

class RegularUser : public User {
    Post* feed;
    int count;
    static const int MAX_FEED_SIZE = 10;
    
    public : 
        RegularUser(string name, string email, string password) : User(name, email, password), feed(new Post[MAX_FEED_SIZE]) {count = 0;}
        
        void addToFeed(Post& post) {
            if(count >= MAX_FEED_SIZE) {
                cout << "No space available in feed to add a post" << endl;
                return;
            }
            
            feed[count++] = post;
        }
        
        void viewFeed() {
            for(int i = 0; i < count; i++) {
                cout << endl << endl << "Post " << i+1 << " : " << endl;
                feed[i].displayDetails();
            }
        }
};

class BusinessUser : public User {
    int count;
    
    public : 
        BusinessUser(string name, string email, string password) : User(name, email, password) {count = 0;}
        
        void promotePost(Post &post) {
            if(count >= 10) {
                cout << "You cant promote any more posts as you have already promoted 10 posts before" << endl;
                return;
            }
            
            post.setLikes(post.getLikes()*2), post.setViews(post.getViews()*3);
            
            count++;
        }
};

int main() {
    cout << "Name : Muhammad Umar" << endl << "Student Id : 23K-0023" << endl << endl;
    
    RegularUser r("Umar", "umar123@gmail.com", "umar123");
    BusinessUser b("Ali", "ali689@gmail.com", "password23");
    
    Post p1(654, "In Turkey"), p2(644, "Game mood"),  p3(464, "Work load!");
    Post p4(547, "Welcome again");
    
    p1.addComment("Nice"), p1.addComment("Good luck"), p1.setLikes(10), p1.setViews(20);
    p2.addComment("true"), p2.addComment("Uss bro uss"), p2.addComment("haha"), p2.setLikes(30), p2.setViews(100);
    p3.addComment("too much"), p3.setLikes(2), p3.setViews(5);
    
    p4.setLikes(152), p4.setViews(350);
    
    r.addToFeed(p1), r.addToFeed(p2), r.addToFeed(p3);
    
    cout << "Regular user's feed" << endl;
    r.viewFeed();
    
    cout << endl << endl << "Business user's post before promotion" << endl;
    p4.displayDetails();
    
    b.promotePost(p4);
    
    cout << endl << endl << "Business user's post after promotion" << endl;
    p4.displayDetails();
    
    return 0;
}

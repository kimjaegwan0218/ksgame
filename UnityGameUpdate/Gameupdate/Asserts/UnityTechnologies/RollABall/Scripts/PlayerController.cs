using UnityEngine;

// Unity UI를 사용하는 데 필요한 네임스페이스 포함
using UnityEngine.UI;

using System.Collections;

public class PlayerController : MonoBehaviour {

    // 플레이어 속도 및 텍스트 UI 게임 개체에 대한 공개 변수 생성
    public float speed;
	public Text countText;
	public Text winText;
    float hAxis;
    float vAxis;

    Vector3 moveVec;
    // 플레이어의 rigidbody 구성 요소에 대한 개인 참조와 지금까지 집어든 물건의 수를 생성합니다.
    private Rigidbody rb;
	private int count;

    // 게임 초반
    void Start ()
	{
        

        // 카운트를 0으로 설정
        count = 0;

        // SetCountText 함수를 실행하여 UI를 업데이트합니다(아래 참조).
        SetCountText();

        // Win Text UI의 text 속성을 빈 문자열로 설정하여 'You Win'(게임 종료 메시지)을 공백으로 만듭니다.
        winText.text = "";
	}

    private void Awake()
    {
        rb = GetComponent<Rigidbody>();
    }
	// Each physics step..
	void FixedUpdate ()
	{
        hAxis = Input.GetAxisRaw("Horizontal");
        vAxis = Input.GetAxisRaw("Vertical");

        //moveVec = new Vector3(hAxis, 0, vAxis).normalized;
        //transform.position += moveVec * speed * Time.deltaTime;

        rb.velocity = new Vector3(hAxis, 0, vAxis) * speed;
	}

    // 이 게임 오브젝트가 'is trigger'가 체크된 콜라이더와 교차할 때,
    // 해당 collider에 대한 참조를 'other'라는 변수에 저장합니다.
    void OnTriggerEnter(Collider other) 
	{
        // ..만약 우리가 교차하는 게임 오브젝트에 '픽업' 태그가 할당되어 있다면..
        if (other.gameObject.CompareTag ("Pick Up"))
		{
            // 다른 게임 개체(픽업)를 비활성화하여 사라지게 합니다.
            other.gameObject.SetActive (false);

            // 점수 변수 'count'에 1을 추가합니다.
            count = count + 1;

            // 'SetCountText()' 함수를 실행합니다(아래 참조).
            SetCountText();
		}
	}

    // 'countText' UI를 업데이트하고 승리에 필요한 금액이 달성되었는지 확인할 수 있는 독립 실행형 함수를 만듭니다.
    void SetCountText()
	{
        // 'countText' 변수의 텍스트 필드 업데이트
        countText.text = "Count: " + count.ToString ();

        // '카운트'가 12 이상인지 확인합니다.
        if (count >= 12) 
		{
            // 'winText'의 텍스트 값을 설정합니다.
            winText.text = "You Win!";
		}
	}
}